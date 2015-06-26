
class Matrix{
    int numberOfLines;
    int numberOfColumns;
    bool isVector;
    double **content;

public:
    Matrix(int numberOfLines, int numberOfColumn);
    ~Matrix();

    void setValue(int line, int column, int newValue);
    double getValue(int line, int column);
    int getNumberOfLines();
    int getNumberOfColumns();
    void printMatrix();
    bool isSquareMatrix();
    Matrix* getTransposed();

    static Matrix* multiplyMatrixByScalar(Matrix *A, double scalar);
    static Matrix* multiplyMatrixByMatrix(Matrix* A, Matrix* B);
    static Matrix* generateIdentityMatrix(int numberOfLines, int numberOfColumns);

};
