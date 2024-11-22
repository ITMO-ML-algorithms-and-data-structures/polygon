void print_matrix(const arma::mat& matrix)
{
    for(auto i = 0; i < matrix.n_rows; i++)
    {
        for(auto j = 0; j < matrix.n_cols; j++)
        {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

double evaluate_dataset(const arma::mat& X, const arma::vec& y)
{
    mlpack::regression::LinearRegression regression;
    double mse = regression.Train(X.t(), y.t());

    return mse;
}