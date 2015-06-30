
class Matrix{
    int numberOfLines;
    int numberOfColumns;
    double **content;

public:
    Matrix(int numberOfLines, int numberOfColumn);
    ~Matrix();

    void setValue(int line, int column, int newValue);
    double getValue(int line, int column);
    int getNumberOfLines();
    int getNumberOfColumns();
    Matrix* getTransposed();
    Matrix* getCopy();

    bool isSquareMatrix();
    void printMatrix();
    double calculeVectorNorm();
    Matrix* normalizeVector();

    static Matrix* multiplyMatrixByScalar(Matrix *A, double scalar);
    static Matrix* multiplyMatrixByMatrix(Matrix* A, Matrix* B);

    static Matrix* subtractMatrixByMatrix(Matrix* A, Matrix* B);

    static Matrix* generateIdentityMatrix(int numberOfLines);

};
