// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution
{
	public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
		unsigned int len_all = nums1.size() + nums2->size();
		int med1, med2;
		if(len_all%2 == 0)
		{
			med1 = len_all/2;
			med2 = 1 + med1;
		}
		else
		{
			med1 = med2 = (1+len_all)/2;
		}


		unsigned int s1 = 0, s2 = 0;
		while(s1 < nums1.size() || s2 < nums2.size())
		{


		}

    }
};