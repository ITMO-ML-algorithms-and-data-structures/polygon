# Добро пожаловать!  

Приветствуем прибывших, получайте удовольствие от программирования, ведь это классно!

# Называем PR по паттерну Поток_Имя_Фамилия_#Лабораторной

### Для начала работы
1. Разберитесь с git (пара видео уроков, а лучше документация помогут вам)   
2. Скопируйте репозиторий   
![alt text](imgs/copy_repo.png)  

```bash
git clone https://github.com/ITMO-ML-algorithms-and-data-structures/polygon.git
```  

3. Представьтесь, это важно
```bash
git config user.email "my@email.com"
```

#### Представляйтесь реальным именем
Это в дискорде вы NyashnyuKotik222, а здесь, будьте добры - Иван Иванович Иванов. Вас 140 человек, и вас нужно идентифицировать
```bash
git config user.name "IvanIvanov333"
```

4. Далее самое простое - решаем лабу, пишем тесты.    
5. Создаем ветку - в формате <group_id>_<surname>_<name>  
Можно так
```bash
git branch 2_dunaev_maxim 
```
(переключиться можно так, а вообще читайте доку, смотрите видосики)   
```bash
git switch 2_dunaev_maxim 
```
6. Создаём PR  
![alt text](./imgs/create_pull_request.png)

[Пример PR](https://github.com/ITMO-ML-algorithms-and-data-structures/polygon/pull/2)

Не забываем - проверить, что тесты прошли!  
Вот так вот не надо  
![alt text](imgs/ci_fail.png)
