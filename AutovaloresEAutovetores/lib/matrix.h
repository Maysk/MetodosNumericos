
class Matrix{
    int numberOfLines;
    int numberOfColumns;
    double **content;

public:
    Matrix();
    Matrix(int numberOfLines, int numberOfColumn);
    ~Matrix();

    void setValue(int line, int column, double newValue);
    double getValue(int line, int column);
    int getNumberOfLines();
    int getNumberOfColumns();
    Matrix getTransposed();
    Matrix getCopy();

    bool isSquareMatrix();
    void printMatrix();

    //Operacoes para vetores
    double calculeVectorNorm();
    Matrix normalizeVector();
    double internProduct(Matrix B);
    //--

    Matrix operator*(double scalar);
    Matrix operator*(Matrix B);
    Matrix operator-(Matrix B);

    static Matrix* generateIdentityMatrix(int numberOfLines);

};
