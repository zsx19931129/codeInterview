# 给你一个graph每一个node都是一个facebook的user，然后找出这个user的两度关系以内所有和他last name一样的人的email address

class FacebookUser(object):
	def __init__(self, uid, firstname, lastname, email):
		self.uid = uid
		self.firstname = firstname
		self.lastname = lastname
		self.email = email

class GraphNode(object):
	def __init__(self, user):
		self.user = user
		self.neighbors = list()

def get_email_addr_within_two_hop(node):
	ret = list()
	visited, q = set(), [node]
	hops = 2
	while q:
		cur_node = q.pop(0)
		visited.add(cur_node.user.uid)
		for neighbor in cur_node.neighbors:
			if neighbor not in visited:
				if neighbor.user.lastname == cur_node.user.lastname:
					result.append(neighbor.user.email)
				q.add(neighbor)
		hops -= 1
		if hops==0:
			break
	return ret