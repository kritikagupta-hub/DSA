class Solution:
    def isValidSerialization(self, preorder:str)-> bool:
        deg=1
        for node in preorder.split(','):
            deg -= 1
            if deg<0:
                return False
            if node != '#':
                deg += 2
        return deg == 0            
    
