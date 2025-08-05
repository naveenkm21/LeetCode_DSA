from typing import List

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        used = [False] * n        # track baskets already used
        unplaced = n              # start with all fruits unplaced

        for qty in fruits:
            for i, cap in enumerate(baskets):
                if not used[i] and cap >= qty:
                    used[i] = True
                    unplaced -= 1
                    break

        return unplaced