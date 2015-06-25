
class Matrix{
    int numberOfLines;
    int numberOfColumn;
    double **content;

public:
    Matrix(int numberOfLines, int numberOfColumn);
    ~Matrix();

    void setValue(int line, int column, int newValue);
    double getValue(int line, int column);

    static bool isMultipliable(Matrix* A, Matrix* B);
    static Matrix* multiplyMatrix(Matrix* A, Matrix* B);
    static Matrix* multiplyMatrix(Matrix* A, Matrix* B, Matrix* C);

};
