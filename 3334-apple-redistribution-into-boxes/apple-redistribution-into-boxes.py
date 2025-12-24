class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apples = sum(apple)
        
        capacity.sort(reverse=True)
        
        boxes = 0
        for c in capacity:
            total_apples -= c
            boxes += 1
            if total_apples <= 0:
                break
        
        return boxes
        