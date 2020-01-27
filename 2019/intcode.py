#-----------------------------------------------------------------------------------------
#class Intcode
#general intcode Computer module to import
#takes the programm as string on init
#can add,multiply,read,write,jump,compare and use parameters in 3 diffrent modi
#quit / init2 can be overwritten to do something at the end/start - does nothing by default
#handleIn and handleOut offer user interface - overwrite:
#handleIn returns an integer
#handleOut takes an integer as parameter
#------------------------------------------------------------------------------------------


class Intcode:
	#__init__
	def __init__(self, string):
			self.initopcode()
			self.x = 0				#current instruction
			self.Memory = []			#Current memory State
			self.offset = 0			#offset used for parametermode 2
			temp = string.split(",")
			for i in temp:
				self.Memory.append(int(i))	#take initial state
			self.Memory = self.Memory + [0] * 10000
	#end of __init__


	def handleIn(self):
		print("input pls")
		return int(input())
	#end of handleIn


	def handleOut(self,output):
		print(output)
	#end of handleOut


	#outputs adress of parameter value (accounts diffrent modes)
	def parametermode(self, parametercount):
		x = self.x	
		if parametercount >= 1:
			if int(self.Memory[x]/100)%10 == 0:
				i1 = self.Memory[x+1]
			elif int(self.Memory[x]/100)%10 == 1:
				i1 = x+1
			else:
				i1 = self.Memory[x+1] + self.offset
		if parametercount >= 2:
			if int(self.Memory[x]/1000)%10 == 0:
				i2 = self.Memory[x+2]
			elif int(self.Memory[x]/1000)%10 == 1:
				i2 = x+2
			else: 
				i2 = self.Memory[x+2] + self.offset
		if parametercount >= 3:
			if int(self.Memory[x]/10000)%10 == 0:
				i3 = self.Memory[x+3]
			elif int(self.Memory[x]/10000)%10 == 1:
				i3 = x+3
			else:
				i3 = self.Memory[x+3] + self.offset

		if parametercount == 3:
			return i1,i2,i3
		if parametercount == 2:
			return i1,i2
		if parametercount == 1:
			return i1
	#end of parametermode


	def add(self):
		i1,i2,o = self.parametermode(3)
		self.Memory[o] = self.Memory[i1] + self.Memory[i2]
		self.x += 4
	#end of add


	def multiply(self):
		i1,i2,o = self.parametermode(3)
		self.Memory[o] = self.Memory[i1] * self.Memory[i2]
		self.x += 4
	#end of multiply


	def read(self):
		i1 = self.handleIn()
		o = self.parametermode(1)
		self.Memory[o] = i1
		self.x += 2
	#end of userInput


	def write(self):
		i = self.parametermode(1)
		self.handleOut(self.Memory[i])
		self.x += 2
	#end of userOutput
	
	
	def jumpiftrue(self):
		i1,i2 = self.parametermode(2)
		if self.Memory[i1] != 0:
			self.x = self.Memory[i2]
		else:
			self.x += 3
	#end of jump-if-true


	def jumpiffalse(self):
		i1,i2 = self.parametermode(2)
		if self.Memory[i1] == 0:
			self.x = self.Memory[i2]
		else:
			self.x += 3
	#end of jump-if-false


	def lessthan(self):
		i1,i2,o = self.parametermode(3)
		if self.Memory[i1] < self.Memory[i2]:
			self.Memory[o] = 1
		else:
			self.Memory[o] = 0
		self.x += 4
	#end of lessthan


	def equalto(self):
		i1,i2,o = self.parametermode(3)
		if (self.Memory[i1]) == (self.Memory[i2]):		
			self.Memory[o] = 1
		else:
			self.Memory[o] = 0
		self.x += 4
	#end of equalto


	#change offset for parametermode 2
	def choffset(self):
		i1 = self.parametermode(1)
		self.offset += self.Memory[i1]
		self.x += 2
	#end of choffset

	
	def quit(self):
		print("quitting")
	#end of quit


	#runs until opcode 99 encountered
	def run(self):
		while True:
			instruction = self.Memory[self.x]%100
			if instruction == 99:
				self.quit()
				break			
			elif instruction in self.opcode:
				self.opcode[instruction]()
			else:
				print("invalid!")
				break
	#end of run


	#links the int opcode to the function
	def initopcode(self):
		self.opcode = {}			
		self.opcode[1] = self.add
		self.opcode[2] = self.multiply
		self.opcode[3] = self.read
		self.opcode[4] = self.write
		self.opcode[5] = self.jumpiftrue
		self.opcode[6] = self.jumpiffalse
		self.opcode[7] = self.lessthan
		self.opcode[8] = self.equalto
		self.opcode[9] = self.choffset
	#end of initopcode

#end of class intcode
