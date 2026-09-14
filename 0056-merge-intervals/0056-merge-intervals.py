class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort(key=lambda x: x[0])

        result = []

        for start, end in intervals:

            # No overlap
            if not result or start > result[-1][1]:
                result.append([start, end])

            # Overlap -> merge
            else:
                result[-1][1] = max(result[-1][1], end)

        return result