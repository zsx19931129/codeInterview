# Problem Description: Implement a jigsaw puzzle. Design the data structures and explain an algorithm to solve the puzzle. You can assume that you have a fits_with method which, when passed two puzzle pieces, returns true if the two pieces belong together.
# CareerCup 8.6
# 这道题让我们设计一个拼图游戏，根据书上的解释，如上图所示是一种最基本的拼图游戏，每一片有四条边，总共有三种边，inner, outer, 和 flat的，角落的一片有两个flat的边，中间的片没有flat的边。那么我们需要一个边类Edge，还需要一个片类Piece，和一个拼图类Puzzle，在拼图类里用init来初始化参数，再用solve来完成拼图。
import math

inner, outer, flat = 1, 2, 3
direction = [[0,1],[1,0],[0,-1],[-1,0]]

class Edge(object):
	def __init__(self, idx, piece, shape):
		self._parent = piece
		self._type = shape
		self._index = idx
		self._attached_to = None

class Piece(object):
	def __init__(self, pid, elist):
		self.pid = pid
		self.edges = elist
		self.rotate = 0

	def rotate(self):
		self.rotate = (self.rotate+90)%360

	def get_edge_by_direction(self, dir):
		return self.edges[(self._index + self.rotate/90)%4]

	def get_type(self):
		pass

	def fits_with(self, piece):
		pass

class Puzzle(object):
	def _put_piece_by_type(self, piece):
		ptype = piece.get_type()
		if ptype == 'inner0':
			self.inner0_pieces.append(piece)
		# elif ptype == 'inner1':
		# ...

	def _remove_piece_by_type(self, piece):
		ptype = piece.get_type()
		if ptype == 'inner0':
			self.inner0_pieces.erase(piece)
		# elif ptype == 'inner1':
		# ...

	def __init__(self, plist):
		self._pieces = dict()
		# use a dict to store pieces
		for p in plist:
			self._pieces[p.pid] = p
		
		self.size = math.sqrt(len(self._pieces))
		# use a 2d array to represent map, value is piece id
		self.map = [[-1 for j in range(self.size)] for i in range(self.size)]
		self.corner_pieces = list()
		self.edge_pieces = list()
		self.inner0_pieces = list()
		self.inner1_pieces = list()
		self.inner2_oppo_pieces, self.inner2_adjacent = list(), list()
		self.inner3_pieces = list()
		self.inner4_pieces = list()

		for p in self._pieces:
			self._put_piece_by_type(p)

	def put_piece(self, i, j, piece):
		self.map[i][j] = piece.pid
		self._remove_piece_by_type(piece)

	def solve_boundary(self):
		self.put_piece(0,0,self.corner_pieces[0])
		curx, cury, curd = 0, 1, 0
		while self.corner_pieces or self.edge_pieces:
			for p in self.edge_pieces:
				if self._pieces[self.map[curx-direction[curd][0]][cury-direction[curd][1]]].fits_with(p):
					self.put_piece(curx, cury, p)
					break
			if self.map[curx][cury] == -1:
				for p in self.corner_pieces:
					if self._pieces[self.map[curx-direction[curd][0]][cury-direction[curd][1]]].fits_with(p):
						self.put_piece(curx, cury, p):
						self.put_piece(curx, cury, p)
						curd += 1
						break
			curx += direction[curd][0]
			cury += direction[curd][1]

	def put_by_constraint(four_constraint, i, j):
		pass

	def solve_by_index(self, i, j):
		four_constraint = list()
		for curd in range(4):
			curx = i - direction[curd][0]
			cury = j - direction[curd][1]
			four_constraint.append(self._pieces[self.map[curx][cury]].get_edge_by_direction(curd) if self.map[curx][cury] else None)

		self.put_by_constraint(four_constraint, i, j)

	def solve(self):
		self.solve_boundary():
		for i in range(1,self.size-1):
			for j in range(1,self.size-1):
				self.solve_by_index(i, j)