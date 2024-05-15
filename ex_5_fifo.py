class FIFOPageReplacement:
    def __init__(self, frame_count):
        self.frame_count = frame_count
        self.frames = []

    def page_fault_occurred(self, page):
        if page not in self.frames:
            if len(self.frames) < self.frame_count:
                self.frames.append(page)
                return True  # Page fault occurred
            else:
                self.frames.pop(0)
                self.frames.append(page)
                return True  # Page fault occurred
        return False  # No page fault occurred

    def print_frames(self):
        print("Current frames: ", self.frames)


fifo = FIFOPageReplacement(3)
pages = [1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5]
page_faults = 0

for page in pages:
    if fifo.page_fault_occurred(page):
        page_faults += 1
    fifo.print_frames()

print("Total number of page faults:", page_faults)
