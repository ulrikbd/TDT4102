#include "tests.h"

void testMatrix() {
    Matrix A{3};
    Matrix B{2, 4};
    Matrix C;
    
    cout << "A:\n" << A;
    cout << "\nB:\n" << B;
    cout << "\nC:\n" << C;

    cout << "A.isValid(): "<< A.isValid() << '\n';
    cout << "C.isValid(): " << C.isValid() << '\n';

    B.set(1, 1, 5);
    cout << B << '\n';
    cout << A.get(1, 1) << '\n';

    Matrix D = B;
    cout << "D = B: \n" << D << '\n';

    Matrix E(D);
    cout << "E(D):\n" << E << '\n';

    E += D;
    cout << "E += D: \n" << E << '\n';
}

void testMatrixArithmetic() {
    Matrix A(2);
    Matrix B(2); 
    Matrix C(2);

    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);

    B.set(0, 0, 4.0);
    B.set(0, 1, 3.0);
    B.set(1, 0, 2.0);
    B.set(1, 1, 1.0);

    C.set(0, 0, 1.0);
    C.set(0, 1, 3.0);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2.0);

    A += B + C;
    cout << "A += B + C:\n" << A << '\n';
}