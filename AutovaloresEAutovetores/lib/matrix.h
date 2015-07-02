
class Matrix{
    int numberOfLines;
    int numberOfColumns;
    double **content;

public:
    Matrix();
    Matrix(const Matrix &obj);
    Matrix(int numberOfLines, int numberOfColumn);
    ~Matrix();

    void setValue(int line, int column, double newValue);
    double getValue(int line, int column) const;
    int getNumberOfLines() const;
    int getNumberOfColumns() const;
    Matrix trocaLinhas(int i, int j) const;
    Matrix getTransposedOfSquareMatrix();
    Matrix getCopy();
    Matrix getInverse() const;
    bool isSquareMatrix() const;
    void printMatrix();

    //Operacoes para vetores
    double calculeVectorNorm();
    Matrix normalizeVector();
    double internProduct(Matrix B);
    Matrix vectorLineToColumn();
    Matrix vectorColumnToLine();
    //--
    Matrix& operator= (const Matrix& other);
    Matrix operator* (double scalar);
    Matrix operator* (Matrix B);
    Matrix operator- (Matrix B);

    static Matrix generateIdentityMatrix(int numberOfLines);

};
