OBJS = obj/main.o obj/sfmlJeu.o obj/Case.o obj/Hud.o obj/Bouton.o obj/Jeu.o obj/Ligne.o obj/Niveau.o obj/Plante.o obj/Projectile.o obj/Soleil.o obj/Terrain.o obj/Tondeuse.o obj/Vecteur2D.o obj/Zombie.o obj/sfmlJeuMenu.o
DEP = src/sfmlJeu.h src/Case.h src/Hud.h src/Bouton.h src/Jeu.h src/Ligne.h src/Niveau.h src/Plante.h src/Projectile.h src/Soleil.h src/Terrain.h src/Tondeuse.h src/Vecteur2D.h src/Zombie.h src/sfmlJeuMenu.h
FLAGS = -Wall -std=c++11
LIB = -Lextern/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -ljpeg
CC = g++
EXEC = bin/jeu.out

all: $(EXEC)

bin/jeu.out: $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ $(LIB)

obj/main.o: src/main.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/sfmlJeu.o: src/sfmlJeu.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Case.o: src/Case.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Hud.o: src/Hud.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Bouton.o: src/Bouton.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Jeu.o: src/Jeu.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Ligne.o: src/Ligne.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Niveau.o: src/Niveau.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Plante.o: src/Plante.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Projectile.o: src/Projectile.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Soleil.o: src/Soleil.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Terrain.o: src/Terrain.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Tondeuse.o: src/Tondeuse.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Vecteur2D.o: src/Vecteur2D.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/Zombie.o: src/Zombie.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

obj/sfmlJeuMenu.o: src/sfmlJeuMenu.cpp $(DEP)
	$(CC) $(FLAGS) -o $@ -c $< $(LIB)

clean:
	rm -rf obj/*.o

veryclean: clean
	rm -rf $(EXEC)

