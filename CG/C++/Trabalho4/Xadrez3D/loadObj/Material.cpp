#include "Material.h"

Material::Material(string nm)
{
	name = nm;

	d = 1.0f;
	ns = 0.0f;
	ka = nullptr;
	kd = nullptr;
	ks = nullptr;

	texFnm = nullptr;
}

bool Material::hasName(string nm)
{
	return name == nm;
}

void Material::setMaterialColors()
{
	if (ka != nullptr) {
		float colorKa[] = { ka->getX(), ka->getY(), ka->getZ(), 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, colorKa);
	}
	if (kd != nullptr) {
		float colorKd[] = { kd->getX(), kd->getY(), kd->getZ(), 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, colorKd);
	}
	if (ks != nullptr) {
		float colorKs[] = { ks->getX(), ks->getY(), ks->getZ(), 1.0f };
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, colorKs);
	}

	if (ns != 0.0f) {
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, ns);
	}

	if (d != 1.0f) {

	}
}

float Material::getD()
{
	return d;
}

float Material::getNs()
{
	return ns;
}

Tuple3 *Material::getKa()
{
	return ka;
}

Tuple3 *Material::getKd()
{
	return kd;
}

Tuple3 *Material::getKs()
{
	return ks;
}

void Material::setD(float val)
{
	d = val;
}

void Material::setNs(float val)
{
	ns = val;
}

void Material::setKa(Tuple3 *t)
{
	ka = t;
}

void Material::setKd(Tuple3 *t)
{
	kd = t;
}

void Material::setKs(Tuple3 *t)
{
	ks = t;
}
