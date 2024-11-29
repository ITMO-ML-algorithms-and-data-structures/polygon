# Функция поиска подсписков с заданной суммой в списке
def findSublists(nums, target):
    array = []
    for i_1 in range(len(nums)-4):
        
        sum_so_far = 0
        # рассматривает все подсписки, начиная с `i` и заканчивая `j`
        for i_2 in range(i_1, len(nums)-3):
            for i_3 in range(i_2+1, len(nums)-2):
                for i_4 in range(i_3+1, len(nums)-1):
                    for i_5 in range(i_4+1, len(nums)):
                        sum_so_far = nums[i_1] + nums[i_2] + nums[i_3] + nums[i_4] + nums[i_5]
                        if sum_so_far == target:
                            array.append([i_1, i_2, i_3, i_4, i_5])

    return array
 

nums = [3, 4, -7, 1, 3, 3, 1, 4, 3, 1]
target = 0

print(nums)
mn_array = findSublists(nums, target)
for i in mn_array:
    print(i)
