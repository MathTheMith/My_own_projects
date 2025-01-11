import random
import copy

class SudokuGenerator:
    def __init__(self):
        self.board = [[0 for _ in range(9)] for _ in range(9)]
        
    def is_valid(self, num, pos):
        # Check row
        for x in range(9):
            if self.board[pos[0]][x] == num and pos[1] != x:
                return False
        
        # Check column
        for x in range(9):
            if self.board[x][pos[1]] == num and pos[0] != x:
                return False
        
        # Check box
        box_x = pos[1] // 3
        box_y = pos[0] // 3
        
        for i in range(box_y * 3, box_y * 3 + 3):
            for j in range(box_x * 3, box_x * 3 + 3):
                if self.board[i][j] == num and (i, j) != pos:
                    return False
        
        return True
    
    def find_empty(self):
        for i in range(9):
            for j in range(9):
                if self.board[i][j] == 0:
                    return (i, j)
        return None
    
    def solve(self):
        find = self.find_empty()
        if not find:
            return True
            
        row, col = find
        
        for num in range(1, 10):
            if self.is_valid(num, (row, col)):
                self.board[row][col] = num
                
                if self.solve():
                    return True
                    
                self.board[row][col] = 0
                
        return False
    
    def generate(self, difficulty="medium"):
        # Fill diagonal boxes first
        for i in range(0, 9, 3):
            nums = list(range(1, 10))
            random.shuffle(nums)
            pos = 0
            for row in range(i, i + 3):
                for col in range(i, i + 3):
                    self.board[row][col] = nums[pos]
                    pos += 1
        
        self.solve()
        solution = copy.deepcopy(self.board)
        
        cells_to_remove = {
            "easy": 30,
            "medium": 40,
            "hard": 50,
            "expert": 60
        }
        
        num_to_remove = cells_to_remove.get(difficulty, 40)
        positions = [(i, j) for i in range(9) for j in range(9)]
        random.shuffle(positions)
        
        for pos in positions[:num_to_remove]:
            self.board[pos[0]][pos[1]] = 0
            
        return self.board, solution
    
    def print_board(self):
        for i in range(9):
            line = ""
            for j in range(9):
                if self.board[i][j] == 0:
                    line += "0"
                else:
                    line += str(self.board[i][j])
                if (j + 1) % 3 == 0 and j < 8:
                    line += "  "
                elif j < 8:
                    line += ""
            print(line)
            if (i + 1) % 3 == 0 and i < 8:
                print()

def main():
    generator = SudokuGenerator()
    puzzle, solution = generator.generate(difficulty="hard")
    
    print("Generated Puzzle:")
    generator.print_board()
    
    print("\nSolution:")
    generator.board = solution
    generator.print_board()

if __name__ == "__main__":
    main()