CFLAGS = -ggdb3 -O0 --std=c99 -Wall -lm `sdl2-config --libs --cflags` -lSDL2_image

FIGURES = src/figures/point.o src/figures/segment.o src/figures/rect.o src/figures/circle.o src/figures/triangle.o

all: main.o src/liste_figure.o src/couleur.o src/gestion_evenement.o src/fichiers_images.o $(FIGURES)
	gcc main.o src/liste_figure.o src/couleur.o src/gestion_evenement.o src/fichiers_images.o $(FIGURES) -o projet $(CFLAGS)

test_couleur: tests/test_couleur.o src/couleur.o
	gcc tests/test_couleur.o src/couleur.o -o tests/test_couleur
	./tests/test_couleur
	rm tests/test_couleur

test_circle: tests/test_circle.o src/figures/circle.o src/couleur.o
	gcc tests/test_circle.o src/figures/circle.o src/couleur.o -o tests/test_circle $(CFLAGS)
	./tests/test_circle
	rm tests/test_circle

test_point: tests/test_point.o src/figures/point.o src/couleur.o
	gcc tests/test_point.o src/figures/point.o src/couleur.o -o tests/test_point $(CFLAGS)
	./tests/test_point
	rm tests/test_point

test_rect: tests/test_rect.o src/figures/rect.o src/couleur.o
	gcc tests/test_rect.o src/figures/rect.o src/couleur.o -o tests/test_rect $(CFLAGS)
	./tests/test_rect
	rm tests/test_rect

test_segment: tests/test_segment.o src/figures/segment.o src/couleur.o
	gcc tests/test_segment.o src/figures/segment.o src/couleur.o -o tests/test_segment $(CFLAGS)
	./tests/test_segment
	rm tests/test_segment

test_triangle: tests/test_triangle.o src/figures/triangle.o src/couleur.o
	gcc tests/test_triangle.o src/figures/triangle.o src/couleur.o -o tests/test_triangle $(CFLAGS)
		./tests/test_triangle
		rm tests/test_triangle

test_liste_figure: tests/test_liste_figure.o src/liste_figure.o src/couleur.o src/figures/triangle.o
	gcc tests/test_liste_figure.o src/liste_figure.o src/couleur.o src/figures/triangle.o -o tests/test_liste_figure $(CFLAGS)
	./tests/test_liste_figure
	rm tests/test_liste_figure

test_fichiers_images: tests/test_fichiers_images.o src/fichiers_images.o src/liste_figure.o src/couleur.o src/figures/triangle.o
	gcc tests/test_fichiers_images.o src/fichiers_images.o src/liste_figure.o src/couleur.o src/figures/triangle.o -o tests/test_fichiers_images $(CFLAGS)
	./tests/test_fichiers_images
	rm tests/test_fichiers_images

test: test_couleur test_circle test_point test_rect test_segment test_triangle test_liste_figure
