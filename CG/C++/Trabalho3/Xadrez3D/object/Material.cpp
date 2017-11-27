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

void Material::showMaterial()
{
	cout << name;
	if (ka != nullptr) {
		cout << "  Ka: " + ka->toString();
	}
	if (kd != nullptr) {
		cout << "  Kd: " + kd->toString();
	}
	if (ks != nullptr) {
		cout << "  Ks: " + ks->toString();
	}
	if (ns != 0.0f) {
		cout << "  Ns: " + to_string(ns);
	}
	if (d != 1.0f) {
		cout << "  d: " + to_string(d);
	}
	if (texFnm != nullptr) {
		cout << "  Texture file: " + (*texFnm);
	}
}

bool Material::hasName(string nm)
{
	return name.compare(nm);
}

void Material::setMaterialColors()
{
	cout << " --- SET MATERIAL COLOR ---";
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
