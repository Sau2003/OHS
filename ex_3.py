import threading

resource_1 = threading.Lock()
resource_2 = threading.Lock()
resource_3 = threading.Lock()

res_allocation = {resource_1: None, resource_2: None, resource_3: None}

def check_deadlock():
    for res, thread in res_allocation.items():
        if thread is None:
            return True  # Deadlock have occurred
    return False  # No deadlock occurred

def process_1():
    with resource_1:
        res_allocation[resource_1] = threading.current_thread().name
        print("Process 1 acquired Resource 1 ")
        with resource_2:
            res_allocation[resource_2] = threading.current_thread().name
            print("Process 1 acquired Resource 2")
        res_allocation[resource_2] = None

def process_2():
    with resource_2:
        res_allocation[resource_2] = threading.current_thread().name
        print("Process 2 acquired Resource 2 ")
        with resource_3:
            res_allocation[resource_3] = threading.current_thread().name
            print("Process 2 acquired Resource 3 ")
        res_allocation[resource_3] = None

def process_3():
    with resource_3:
        res_allocation[resource_3] = threading.current_thread().name
        print("Process 3 acquired Resource 3")
        with resource_1:
            res_allocation[resource_1] = threading.current_thread().name
            print("Process 3 acquired Resource 1")
        res_allocation[resource_1] = None

# Creating threads for each process
thread1 = threading.Thread(target=process_1, name="Process 1")
thread2 = threading.Thread(target=process_2, name="Process 2")
thread3 = threading.Thread(target=process_3, name="Process 3")

thread1.start()
thread2.start()
thread3.start()

thread1.join()
thread2.join()
thread3.join()

if check_deadlock():
    print("Deadlock Occurred")
else:
    print("No Deadlock Occurred")
