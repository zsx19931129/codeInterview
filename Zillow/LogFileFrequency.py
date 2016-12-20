# 给你一个log file，每一行都有一条记录，包括三个数据：访问时间，user id，访问的page id。然后让你找出访问次数最多的10组3个连续访问page。就是如果user A访问了page 1 2 3，这样 1 2 3 就算被访问了一次。不用考虑时间间隔所以我昨天访问1，今天2，后天3，也能算作连续访问page。我的做法是先用map统计了所有用户的按时间顺序排列好的访问page，然后三个三个加到另一个map里面去count(我用最土的办法 id1_id2_id3 下划线连接)，最后用minHeap找出前10个

class Log(object):
	def __init__(self, timestamp, userid, pageid):
		self.ts = timestamp
		self.uid = userid
		self.pid = pageid

class heap(object):
	def swap(self, i, j):                    
    	self.arr[i], self.arr[j] = self.arr[j], self.arr[i] 

	def heapify(self,end,i):   
	    l=2 * i + 1  
	    r=2 * (i + 1)   
	    max=i   
	    # if l < end and self.arr[i] < self.arr[l]:   
	    if l < end and self.cmp(i, l):
	        max = l   
	    # if r < end and self.arr[max] < self.arr[r]:   
	    if r < end and self.cmp(max, r):
	        max = r   
	    if max != i:   
	        self.swap(i, max)   
	        self.heapify(end, max)

	def cmp(self):
		pass
	
	def __init__(self, array):
		self.arr = array
		end = len(self.arr)   
	    start = end // 2 - 1 # use // instead of /
	    for i in range(start, -1, -1):   
	        self.heapify(end, i)

	def sort(size=None):
		alen = len(self.arr)
		if size == None:
			size = alen-1
		for i in range(alen-1, alen-1-size, -1):
			self.swap(i, 0)
			self.heapify(i, 0)

class maxheap(heap):
	def __init__(self, array):
		super(maxheap, self).__init__(array)

	def cmp(self, i, j):
		return self.arr[i][1] < self.arr[j][1]

def get_max_frequency_triple_page(logfile):
 	'''
    :param logfile: list of log 
    :return: start index of max frequency triple page
    '''
    # sort by timestamp
    logfile = sorted(logfile, key=lambda log: log.ts, reverse=False)
    # key: uid, value: query count
    query_count = dict()
    # key: uid, value: list() of page query, size is 3
    user_list = dict()
    for log in logfile:
    	if user_list.get(log.uid, None):
    		if len(user_list[log.uid]) == 3:
    			user_list[log.uid].pop(0)
    		user_list[log.uid].append(log.pid)
    		if len(user_list[log.uid]) == 3:
    			if user_list[log.uid][2] == user_list[log.uid][1]+1:
    				if user_list[log.uid][1] == user_list[log.uid][0]+1:
    					if query_count.get(log.uid, None):
    						query_count[log.uid] += 1
    					else:
    						query_count[log.uid] = 1
    				else:
    					user_list[log.uid].pop(0)
    			else:
    				user_list[log.uid].pop(0)
    				user_list[log.uid].pop(0)
    	else:
    		user_list[log.uid] = [log]

    array = [(k,v) for k,v in query_count.items()] 
    mh = maxheap(array)
    mh.sort(10)
    return mh.arr[-10:]
