//Oscar Emiliano Cervantes del Valle A01332891
#include "cCube.h"

Cube::Cube(float side, bool use_mipmaps)
{
	this->side = side;
	hside = side / 2.0f;

	for (int t = 0; t < 6; t++)
	{
		glGenTextures(1, &targas[1].texID);
		glBindTexture(GL_TEXTURE_2D, targas[1].texID);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

		switch (t)
		{
		case 0: LoadTGA(&targas[t], "assets/cube_front.tga"); break;
		case 1: LoadTGA(&targas[t], "assets/cube_back.tga"); break;
		case 2: LoadTGA(&targas[t], "assets/cube_left.tga"); break;
		case 3: LoadTGA(&targas[t], "assets/cube_right.tga"); break;
		case 4: LoadTGA(&targas[t], "assets/cube_top.tga"); break;
		case 5: LoadTGA(&targas[t], "assets/cube_bottom.tga"); break;
		default:
			break;
		}

		if (use_mipmaps)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

			gluBuild2DMipmaps(GL_TEXTURE_2D, 3, targas[t].width, targas[t].height, GL_RGB, GL_UNSIGNED_BYTE, targas[t].imageData);
		}
		else {
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, targas[t].width, targas[t].height, 0, GL_RGB, GL_UNSIGNED_BYTE, targas[t].imageData);
		}
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

Cube::~Cube(void)
{
	glDeleteTextures(1, &targas[0].texID);
	glDeleteTextures(1, &targas[1].texID);
	glDeleteTextures(1, &targas[2].texID);
	glDeleteTextures(1, &targas[3].texID);
	glDeleteTextures(1, &targas[4].texID);
	glDeleteTextures(1, &targas[5].texID);
}

void Cube::draw(void)
{
	glBindTexture(GL_TEXTURE_2D, targas[0].texID);
	//FRONT
	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, -hside, hside);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(hside, -hside, hside);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, hside);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-hside, hside, hside);
	}
	glEnd();

	//Cara Tracera
	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, -hside, -hside);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(hside, -hside, -hside);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, -hside);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-hside, hside, -hside);
	}

	//En izq y derecha se manejan vertex en x
	//Draw izq
	glBegin(GL_QUADS);
	{
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, -hside, -hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-hside, -hside, hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(-hside, hside, hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-hside, hside, -hside);
	}
	glEnd();

	//Draw derecha
	glBegin(GL_QUADS);
	{
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(hside, -hside, -hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(hside, -hside, hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, hside);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(hside, hside, -hside);
	}
	glEnd();

	//Cara Arriba
	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, hside, -hside);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-hside, hside, hside);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, hside, hside);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(hside, hside, -hside);
	}
	glEnd();

	//Cara Abajo
	glBegin(GL_QUADS);
	{
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-hside, -hside, -hside);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(-hside, -hside, hside);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(hside, -hside, hside);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(hside, -hside, -hside);
	}
	glEnd();
	glBindTexture(GL_TEXTURE_2D, NULL);
}
