#include <array>
#include <vector>
#include <algorithm>

#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#include <mlpack.hpp>

/**
 * @brief ������� �������� ������ �� (������� �����), ������������ ������� ��������
 *
 * ������� ��������� �� ���� ����� ������, � ������� �������� �������� � ������ ��������.
 * ������ ��������: ������� ������ �������, ���� �� ����; ������� ������� �������, ������� ������
 * � ������� ������� ��������
 *
 * @param[in] dataset ����� ������
 * @param[in] target_column_index ������ �������� ������� (������� � �������� � ������� 0)
 * @param[in] id_column_index ������ id ��� index ������� ���� �� ����, ������� �� ����� ������ ��� ��������
 * @return ������� �������� RMSE
 */
inline double evaluate_dataset(const arma::mat& features, const arma::subview_row<double>& target) {
    // ������� ������ ������
    mlpack::regression::LinearRegression lr;

    // ������� ������ � �������� ������� ��������
    const double rmse = lr.Train(features, target);

    return rmse;
}