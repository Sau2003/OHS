class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}
        self.queue = []

    def get(self, key):
        if key in self.cache:
            # Move the key to the end to indicate it was most recently used
            self.queue.remove(key)
            self.queue.append(key)
            return self.cache[key]
        else:
            return -1

    def put(self, key, value):
        if key in self.cache:
            # If key already exists, update its value and move it to the end
            self.queue.remove(key)
            self.queue.append(key)
            self.cache[key] = value
        else:
            if len(self.cache) >= self.capacity:
                # If cache is full, remove the least recently used item
                lru_key = self.queue.pop(0)
                del self.cache[lru_key]
            self.queue.append(key)
            self.cache[key] = value

# Example usage:
cache = LRUCache(2)  # Capacity of 2

cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))  # Output: 1
cache.put(3, 3)       # evicts key 2
print(cache.get(2))  # Output: -1 (not found)
cache.put(4, 4)       # evicts key 1
print(cache.get(1))  # Output: -1 (not found)
print(cache.get(3))  # Output: 3
print(cache.get(4))  # Output: 4
