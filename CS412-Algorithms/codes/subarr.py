# Brute Force

def bf_maxsubarr(nums):
    max_sum = float('-inf')
    for i in range(len(nums)):
        curr_sum = 0
        for j in range(i, len(nums)):
            curr_sum += nums[j]
            max_sum = max(max_sum, curr_sum)
    return max_sum

# Divide and Conquer

def maxCrossingSum(arr, l, m, h): 
    sm = 0; left_sum = -10000
  
    for i in range(m, l-1, -1): 
        sm = sm + arr[i] 
        if (sm > left_sum): left_sum = sm 
   
    sm = 0; right_sum = -1000
    for i in range(m, h + 1):
        sm = sm + arr[i] 
  
        if (sm > right_sum): right_sum = sm 
    
    return max(left_sum + right_sum - arr[m], left_sum, right_sum) 
  
  
# Returns sum of maximum sum subarray in aa[l..h] 
def maxSubArraySum(arr, l, h): 
    if (l > h): return -10000
    if (l == h): return arr[l] 
  
    m = (l + h) // 2
    return max(maxSubArraySum(arr, l, m-1), maxSubArraySum(arr, m+1, h), maxCrossingSum(arr, l, m, h)) 



if __name__ == '__main__':
    # nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    # nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    nums = [-2, -5, 6, -2, -3, 1, 5, -6]
    print(bf_maxsubarr(nums))   
    # print(dc_maxsubarr(nums, 0, len(nums)-1))