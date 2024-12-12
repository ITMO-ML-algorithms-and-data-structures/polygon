class Solution:
    def maxnumber(self, nums1, nums2, k):
        m, n = len(nums1), len(nums2)
        end_nums = []
        for i in range(max(0, k - n), min(k, m) + 1):
            # print(res, self.mergenums(self.maxnums(nums1, i), self.maxnums(nums2, k - i)))
            end_nums = max(end_nums, self.mergenums(self.maxnums(nums1, i), self.maxnums(nums2, k - i)))
        return end_nums

    def maxnums(self, nums, k):
        i = len(nums) - k
        end_nums = []
        for num in nums:
            while i > 0 and len(end_nums) != 0 and end_nums[-1] < num:
                end_nums.pop()
                i -= 1
            end_nums.append(num)
        return end_nums[:k]

    def mergenums(self, nums1, nums2):
        end_nums = []
        while nums1 or nums2:
            if nums1 > nums2:
                mas = nums1
            else:
                mas = nums2
            # tmp = nums1 if nums1 > nums2 else nums2
            end_nums.append(mas[0])
            mas.pop(0)
        return end_nums


nums1 = [3,4,6,50]
nums2 = [9,1,2,5,8,3]
k=5
x = Solution()
print(x.maxnumber(nums1, nums2, k))
