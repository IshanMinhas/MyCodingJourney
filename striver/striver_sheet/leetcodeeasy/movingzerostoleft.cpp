void moveZeroes(vector<int>& nums)
{
    stable_partition(begin(nums),end(nums),logical_not<int>());
}

or two pointer