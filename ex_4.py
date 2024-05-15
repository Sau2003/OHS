import os
import multiprocessing

def child_process(message, pipe_out):
    pipe_out.send(message.encode())
    pipe_out.close()

def parent_process(pipe_in):
    message = pipe_in.recv().decode()
    print("Message received from child process:", message)

if __name__ == "__main__":
    # Get the message from the user
    message = input("Enter the message: ")

    # Creating a pipe
    pipe_in, pipe_out = multiprocessing.Pipe()

    # Creating a child process
    child = multiprocessing.Process(target=child_process, args=(message, pipe_out))
    child.start()
    child.join()

    # Close the write end of the pipe in the parent
    pipe_out.close()

    # Read the message from the pipe in the parent
    parent_process(pipe_in)

