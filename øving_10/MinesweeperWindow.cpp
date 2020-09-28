#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}, openedTiles{0}
	//Initialiser medlemsvariabler, bruker ogsaa konstruktoren til Windowsklassen
{
	// Legg til alle tiles paa vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i* cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{x, y}, cellSize, cb_click });
			attach(tiles.back());
		}
	}
	//Legg til miner paa tilfeldige posisjoner
	srand(static_cast<unsigned int>(time(nullptr)));
	int mineCell;
	while (mines) {
		mineCell = rand() % (width * height - 1);
		if (!tiles[mineCell].getIsMine()) {
			tiles[mineCell].setIsMine(true);
			mines--;
		}
	}
	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int mineCount = 0;
	for (auto &p: points) {
		if (at(p).getIsMine()) mineCount++;
	}
	return mineCount;
};
vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile& t = at(xy);
	if (t.getState() == Cell::closed) {
		t.open();
		if (t.getIsMine()) {
			for (int i = 0; i < tiles.size(); ++i) {
				tiles[i].open();
			}
			feedback(false);
		} else {
		openedTiles++;
		vector<Point> adjP;
		int numMines;

		adjP = adjacentPoints(xy);
		numMines = countMines(adjP);
		if (numMines) {
			t.setAdjMines(numMines);
		} 
		else {
			for (int i = 0; i < adjP.size(); ++i) {
				openTile(adjP[i]);
			}
		}
		if (checkWin()) feedback(true);
		}
	}
}

void MinesweeperWindow::feedback(bool win) {
	string s;
	if (win) {
		s = "Gratulerer du vant!";
	} else s = "Der var det desverre en mine gitt!";

	cout << s;
	Text t{Point{0,0}, s};
}
	
bool MinesweeperWindow::checkWin() const {
	if (width*height - openedTiles == mines) return true;
	else return false;
}

void MinesweeperWindow::flagTile(Point xy) {
	if (at(xy).getState() != Cell::open) {
		at(xy).flag();
	}
}

//Kaller opentile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}
