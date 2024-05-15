from collections import defaultdict

class OptimalPageReplacement:
    def __init__(self, frame_count):
        self.frame_count = frame_count
        self.frames = []
        self.page_table = defaultdict(list)

    def page_fault_occurred(self, pages):
        page_faults = 0
        for index, page in enumerate(pages):
            if page not in self.frames:
                page_faults += 1
                if len(self.frames) < self.frame_count:
                    self.frames.append(page)
                else:
                    # Find the page that will not be used for the longest period in the future
                    page_to_replace = max(self.frames, key=lambda x: self.page_table[x][self.page_table[x].index(index)+1:] if index in self.page_table[x] else float('inf'))
                    self.frames[self.frames.index(page_to_replace)] = page
            self.page_table[page].append(index)
        return page_faults

    def print_frames(self):
        print("Current frames:", self.frames)

# Example usage:
if __name__ == "__main__":
    opt = OptimalPageReplacement(3)
    pages = [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4]
    page_faults = opt.page_fault_occurred(pages)
    opt.print_frames()
    print("Total number of page faults:", page_faults)
