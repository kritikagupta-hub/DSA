class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        if not digits:
            return []

        mapping = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
        }

        result = []
        current = []
        
        def backtrack(digit_index, current):
            if digit_index == len(digits):
                result.append("".join(current))
                return

            digit = digits[digit_index]
            letters = mapping[digit]

            for letter in letters:
                current.append(letter)
                backtrack(digit_index+1, current)
                current.pop()

        backtrack(0, [])

        return result




        