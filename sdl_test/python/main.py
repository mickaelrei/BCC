import pygame
from pygame.locals import *
import sys, random
from copy import deepcopy

pygame.init()

WIDTH = 600
HEIGHT = 600
FPS = 60
window = pygame.display.set_mode((WIDTH, HEIGHT))
clock = pygame.time.Clock()

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)

class ConwayBoard:
    def __init__(self, cols: int, rows: int) -> None:
        self.cols = cols
        self.rows = rows

        self.next_board = [0] * cols * rows
        self.current_board = [0] * cols * rows
        for i in range(cols * rows):
            self.current_board[i] = random.randint(0, 1) 

    def getIndexFromCoord(self, x: int, y: int):
        return y * self.cols + x

    def getNeighbors(self, x: int, y: int):
        neighbors = []
        for nx in range(-1, 2):
            for ny in range(-1, 2):
                if nx == 0 and ny == 0: continue

                dx = x + nx
                dy = y + ny

                if dx < 0 or dx >= self.cols: continue
                if dy < 0 or dy >= self.rows: continue

                idx = self.getIndexFromCoord(dx, dy)
                neighbors.append(self.current_board[idx])

        return neighbors

    def loop(self):
        while True:
            for event in pygame.event.get():
                if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
                    pygame.quit()
                    sys.exit()
                elif event.type == KEYDOWN:
                    if event.key == K_e:
                        self.update()
            
            self.update()
            self.draw()

            pygame.display.update()
            clock.tick(FPS)

    def checkCell(self, x, y, countAlive):
        idx = self.getIndexFromCoord(x, y)
        if self.current_board[idx] == 1:
            if countAlive == 2 or countAlive == 3:
                return 1
            return 0
        else:
            if countAlive == 3:
                return 1
            return 0        

    def update(self):
        for y in range(self.rows):
            for x in range(self.cols):
                neighbors = self.getNeighbors(x, y)

                countAlive, countDead = 0, 0
                for neighbor in neighbors:
                    if neighbor == 0:
                        countDead += 1
                    else:
                        countAlive += 1

                cellIdx = self.getIndexFromCoord(x, y)
                self.next_board[cellIdx] = self.checkCell(x, y, countAlive)

        for i in range(self.cols * self.rows):
            self.current_board[i] = self.next_board[i]

    def draw(self):
        w = WIDTH / self.cols
        h = HEIGHT / self.rows

        window.fill(BLACK)
        for x in range(self.cols):
            for y in range(self.rows):
                idx = self.getIndexFromCoord(x, y)
                value = self.current_board[idx]

                xPos = w * x
                yPos = h * y
                if value == 1:
                    pygame.draw.rect(window, (200, 200, 200), (xPos, yPos, w, h))

app = ConwayBoard(20, 20)
app.loop()