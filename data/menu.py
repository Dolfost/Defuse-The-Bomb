number = "1" #None
file = open("data/coredata/menuchoose.dat", "w+")
fail = False

print("\033[2J\033[1;1H")

while number != "4":
  print("""
       ____________________
      |                    |
      |   Play -      1    |
      |                    |
      |   Scores -    2    |
      |                    |
      |   Settings -  3    |
      |                    |
      |   Exit -      4    |
      |____________________|
""")
  if fail == True:
  	print("       Invalid choise (", number, "). Try again...\n")
  	fail = True 
  number = input("       Enter your choice: ")
  if number == "1":
    file.write("1")
    break
  elif number == "2":
    file.write("2")
    break
  elif number == "3":
    file.write("3")
    break
  elif number == "4":
    print("Goodbye")
    file.write("4")
  else:
  	fail = True
  print("\033[2J\033[1;1H")
file.close()
