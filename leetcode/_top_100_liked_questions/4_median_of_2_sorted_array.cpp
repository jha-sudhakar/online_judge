class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
    	int s1 = 0, e1 = nums1.size()-1;
    	int s2 = 0, e2 = nums2.size()-1;
		int k1 =
		int k2 = (e1+1 + e2+1)/2;

    	while((s1 != e1) && (s2 != e2))
    	{
			int m1 = (s1+e1)/2;
			int m2 = (s2+e2)/2;

			l1 = m1-s1+1;
			l2 = m2-s2+1;

			if(l1+l2 >= k2)
			{
				e1 = m1;
				e2 = m2;
			}
			else
			{
				s1 = 1+m1;
				s2 = 1+m2;
			}

		}
    }
};