
import sys
from websocket_server import WebsocketServer
from time import sleep
from threading import Thread
import os

server = WebsocketServer(host="localhost", port=8001, loglevel=3)

client = None
kill = False

msgq = []

def newclient(a,b):
  global client
  client = a

def clientleft(a,b):
  global client
  client = None

def msg(a,b,c):
  global msgq
  msgq.append(c)

# Setup server
server.set_fn_new_client(newclient)
server.set_fn_client_left(clientleft)
server.set_fn_message_received(msg)

# Setup tick
def Tick():
  global client
  global kill
  global server
  global msgq

  while kill == False:
    while len(msgq) > 0:
      if os.path.exists("./to_nn.sandbox_nn.lock"):
        break

      lock = open("to_nn.sandbox_nn.lock", "w")
      to_nn = open("to_nn.sandbox_nn", "a")
      to_nn.write(msgq[0])
      to_nn.write("\n")
      to_nn.close()
      lock.close()
      os.remove("to_nn.sandbox_nn.lock")

      del msgq[0]

    if client == None:
      sleep(1)
      continue
    
    if os.path.exists("./to_gui.sandbox_nn.lock"):
      continue

    lock = open("to_gui.sandbox_nn.lock", "w")
    to_gui = open("to_gui.sandbox_nn", "r+")
    lines = to_gui.readlines()
    to_gui.truncate(0)
    to_gui.close()
    lock.close()
    os.remove("to_gui.sandbox_nn.lock")

    if len(lines) > 0:
      print(f"lines: {lines}")
      sys.stdout.flush()

      for line in lines:
        server.send_message(client, line)

    sleep(1)

tickthread = Thread(target=Tick)
tickthread.start()

server.run_forever()

kill = True

tickthread.join()
