class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size(); // Размер строки
        std::vector<int> results; // Массив с результами 

        for (int i = 0; i < n; i++) {
            // Ищим операцию
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {

                // Разделяем строку на две части (до и после знака)
                std::string left = expression.substr(0, i);
                std::string right = expression.substr(i + 1);

                // Делаем рекурсию
                // Получаем массивы всех возможных значений над которым проводится операция 
                std::vector<int> leftResult = diffWaysToCompute(left);
                std::vector<int> rightResult = diffWaysToCompute(right);
                
                // Далле просто проводим операции в зависимости от знака
                // Массив всех итоговых операций и будет наш результат
                for (int l : leftResult) {
                    for (int r : rightResult) {
                        if (expression[i] == '+') {
                            results.push_back(l + r);
                        } else if (expression[i] == '-') {
                            results.push_back(l - r);
                        } else if (expression[i] == '*') {
                            results.push_back(l * r);
                        }
                    }
                }
            }
        }
        // Если нет операций в строке
        if (results.empty()) {
            results.push_back(std::stoi(expression));
        }

        return results;
    }    
};
