# Implement a function for blackjack that returns the score of your hand
# 先让你定义一个interface， ICard，应该有哪些函数。然后让写个函数，给你一个hand的扑克牌，求最大的小于等于21的分数，如果没有的话，求最小的大于21的分数。求分数的话，只有ace可能有两种分数，11或者1。他给的提示就是如果有ace的话，ace最多只可能有一个使用11，所以思路就是求出这堆扑克牌的最小值（ace全部取1），然后如果最小值小于21且加上10仍小于21，那就返回最小值+11，else返回最小值

class ICard(object):
	name_value = {'Ace':1, 'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10, 'Queen':10, 'King':10}
	def __init__(self, name):
		self.name = name

	def get_value(self):
		return ICard.name_value[self.name]

def score(cardlist):
	score = 0
	has_ace = False
	for card in cardlist:
		score += card.get_value()
		if card.get_value() == 1:
			has_ace = True

	if score < 21 and has_ace:
		return score+10 if score+10<=21 else score
	else:
		return score