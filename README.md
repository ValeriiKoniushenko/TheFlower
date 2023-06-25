# The Flower Game

# ⭐ Intro
I have created a game about flowers and snakes. We should survive! Plant a flower and don't be killed by a snake!

![Animation](https://github.com/ValeriiKoniushenko/TheFlower/assets/99877553/23269175-c4bc-4f36-a610-ad1ff59b16af)

# 🔧 How to install a binaries
- Go to releases(right tab)
- Download .zip file
- Unpack it
- Play!

# 🔧 How to build
- Download GIT([download](https://git-scm.com/downloads))
- Clone the repository using ```git clone https://github.com/ValeriiKoniushenko/TheFlower.git```
- Go to folder with a local repo
- Run next command using a terminal: ```mkdir build```
- Run next command using a terminal: ```cd build```
- Install cmake([download](https://cmake.org/download/))
- Install cmake to a window's PATH([how to do it](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/))
- Run next command using a terminal: ```cmake ../```
- Run next command using a terminal: ```cmake --build .```

# 📢 Technical points
- Serializing of all data(the Window_'s size, warms' position, flowers' position etc)
- Wrote GTest-s for testing core parts of the game
- Supporting of GameStates
- Implemented main UI features: Widget, Canvas, Button
- Implemented a game economic: we can plant every 0.5 second one Flower and get 5 coins per 3 seconds
- Non-discreet world
- Scalable architecture
- Supportable

# 📞 Feedback & Contacts
You can send me e-mail: Valerii.Koniushenko@gmail.com or try to find me in telegram: @markmoran24