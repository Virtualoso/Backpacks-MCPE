#pragma once

class Vec3;
class TextureOffset;
class Model;
class AABB;
class GeometryPtr;
class Tessellator;
class Matrix;

class ModelPart {
public:

		//again, too lazy
		char filler[0xC8];
		
		ModelPart(ModelPart&&);
		ModelPart(int, int, int, int);
		
		void addBox(Vec3 const&, Vec3 const&, bool, float);
		void addBox(Vec3 const&, Vec3 const&, float);
		void addBoxMapTex(Vec3 const&, Vec3 const&, TextureOffset const&, bool float);
		void addBoxMapTex(Vec3 const&, Vec3 const&, TextureOffset const&, float);
		void addChild(ModelPart*);
		void compile(float);
		void draw(Model const&, float);
		void expandAABB(AABB&) const;
		Vec3* getOrigin() const;
		void load(GeometryPtr const&, std::string const&, ModelPart*);
		void mimic(ModelPart const&);
		void operator=(ModelPart&&);
		void render(Model const&, float);
		void reset();
		void setNeverRender(bool);
		void setOrigin(Vec3 const&);
		void setPos(Vec3 const&);
		void setTexSize(int, int);
		void tessellate(Tessellator&, float);
		void texOffs(int, int);
		void translateTo(Matrix&, float);
};