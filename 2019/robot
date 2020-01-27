import os
import time
from intcode import Intcode

#functions to inject into intcode

class Robot(Intcode):
	def __init__(self,string):
		super().__init__(string)		
		self.field = {}				#the field the drone scanned
		self.currentpos = [0,0]		#current position
		self.direction = 1			#direction of the current movement order
		self.laststatus = 0			#last status code needed for mouse
		self.right = {}				#reverse direction
		self.right[1] = 4
		self.right[2] = 3
		self.right[3] = 1
		self.right[4] = 2
		self.left = {}
		self.path2 = 0
		self.tank = [0,0]
		self.outer = set()
		for i in self.right:
			self.left[i] = self.right[self.right[self.right[i]]]
	#end of init2


	def updatescreen(self):
		for i in self.outer:
			self.field[i] = "O"
		#time.sleep(0.005)
		os.system("clear")
		ranges = [0,0,0,0]
		for position in self.field:
			if position[0] < ranges[0]:	ranges[0] = position[0]
			if position[0] > ranges[1]:	ranges[1] = position[0]
			if position[1] < ranges[2]:	ranges[2] = position[1]
			if position[1] > ranges[3]:	ranges[3] = position[1]
		for y in reversed(range(abs(ranges[2]) + abs(ranges[3]) + 1)):
			temp = ""
			for x in range(abs(ranges[0]) + abs(ranges[1]) + 1):
				if (x+ranges[0],y+ranges[2]) in self.field:
					if ([x+ranges[0],y+ranges[2]] == self.currentpos) and (self.outer == set()):
						temp += "P"					
					elif self.field[(x+ranges[0],y+ranges[2])] == "#":
						temp += "."
					elif self.field[(x+ranges[0],y+ranges[2])] != "O":
						temp += " "
					else:
						temp += "O"
					#temp += self.field[(x+ranges[0],y+ranges[2])]
				else:
					temp += " "
			print(temp)	
	#end of updatescreen


	def handleIn(self):
		"""
		print("north 1, south 2, west 3, east 4")
		temp = ""
		while not(temp in ["1","2","3","4"]):
			temp = input()	
		self.direction = int(temp)
		return self.direction
		"""
		#left-hand wall
		if (self.path2 != 0) and (self.currentpos == [0,0]):
			self.Oxygen()
			return "thisisinvalidoutput"
		if self.laststatus == 0:
			self.direction = self.left[self.direction]
		else:
			self.direction = self.right[self.direction]
		return self.direction
	#end of handleIn


	def handleOut(self, response):
		self.laststatus = response
		x = 0
		y = 0
		cx = self.currentpos[0]
		cy = self.currentpos[1]
		if self.direction == 1:
			y = 1
		elif self.direction == 2:
			y = -1
		elif self.direction == 3:
			x = -1
		elif self.direction == 4:
			x = 1
		if response == 0:
			self.field[(cx+x,cy+y)] = "#"
		if response > 0:
			self.field[(cx+x,cy+y)] = "."
			self.currentpos = [cx+x,cy+y]
		if response == 2:
			self.tank = (self.currentpos[0],self.currentpos[1])
			self.path2 = 1
		self.updatescreen()
	#end of handleOut


	#outputs a list of the coordinates of adjecent tiles (x,y)-tuple
	def adjecent(self, current):
		out = []
		out.append((current[0]+1,current[1]))
		out.append((current[0]-1,current[1]))
		out.append((current[0],current[1]+1))
		out.append((current[0],current[1]-1))
		return out
	#end of adjecent


	#flood room with oxygen after full scan
	def Oxygen(self):
		self.empty = set()
		self.outer = set()
		for unit in self.field:
			if self.field[unit] == ".":
				self.empty.add(unit)
		self.empty.remove(self.tank)
		self.outer.add(self.tank)
		self.updatescreen()
		
		self.time = 0
		while len(self.empty) > 0:
			self.time += 1
			self.temp = set()
			for i in self.outer:
				self.temp.add(i)
			for current in self.temp:
				for close in self.adjecent(current):
					if close in self.empty:
						self.empty.discard(close)
						self.outer.add(close)
			self.updatescreen()
			
		print(self.time)
	#end of oyxgen
#end of Robot
data = open("robot.dat","r")
robot = Robot(data.readline().rstrip())
robot.run()

