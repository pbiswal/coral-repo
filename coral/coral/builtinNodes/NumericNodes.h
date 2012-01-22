// <license>
// Copyright (C) 2011 Andrea Interguglielmi, All rights reserved.
// This file is part of the coral repository downloaded from http://code.google.com/p/coral-repo.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
// 
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// </license>


#ifndef CORAL_NUMERICNODES_H
#define CORAL_NUMERICNODES_H

#include "../src/Node.h"
#include "../src/Attribute.h"
#include "../src/NumericAttribute.h"
#include "../src/PassThroughAttribute.h"
#include "../src/StringAttribute.h"
#include "LoopNodes.h"

namespace coral{
class Numeric;

class IntNode : public Node{
public:
	IntNode(const std::string &name, Node *parent);
		
private:
	NumericAttribute *_out;
};

class FloatNode : public Node{
public:
	FloatNode(const std::string &name, Node *parent);
	
private:
	NumericAttribute *_out;
};

class Vec3Node: public Node{
public:
	Vec3Node(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_x;
	NumericAttribute *_y;
	NumericAttribute *_z;
	NumericAttribute *_vector;
};

class Vec3ToFloats: public Node{
public:
	Vec3ToFloats(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	
private:
	NumericAttribute *_vector;
	NumericAttribute *_x;
	NumericAttribute *_y;
	NumericAttribute *_z;
};

class Col4Node: public Node{
public:
	Col4Node(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_r;
	NumericAttribute *_g;
	NumericAttribute *_b;
	NumericAttribute *_a;
	NumericAttribute *_color;
};

class Col4ToFloats: public Node{
public:
	Col4ToFloats(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_color;
	NumericAttribute *_r;
	NumericAttribute *_g;
	NumericAttribute *_b;
	NumericAttribute *_a;
};

class Col4Reverse: public Node{
public:
	Col4Reverse(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_inColor;
	NumericAttribute *_outColor;
};

class QuatNode: public Node{
public:
	QuatNode(const std::string &name, Node *parent);

	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_r;
	NumericAttribute *_x;
	NumericAttribute *_y;
	NumericAttribute *_z;
	NumericAttribute *_quat;
};

class QuatToFloats: public Node{
public:
	QuatToFloats(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_quat;
	NumericAttribute *_r;
	NumericAttribute *_x;
	NumericAttribute *_y;
	NumericAttribute *_z;
};

class Matrix44Node: public Node{
public:
	Matrix44Node(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);

private:
	NumericAttribute *_translateX;
	NumericAttribute *_translateY;
	NumericAttribute *_translateZ;
	NumericAttribute *_eulerX;
	NumericAttribute *_eulerY;
	NumericAttribute *_eulerZ;
	NumericAttribute *_scaleX;
	NumericAttribute *_scaleY;
	NumericAttribute *_scaleZ;
	NumericAttribute *_matrix;
};

class ConstantArray: public Node{
public:
	ConstantArray(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	
private:
	NumericAttribute *_size;
	NumericAttribute *_constant;
	NumericAttribute *_array;
};

class ArraySize: public Node{
public:
	ArraySize(const std::string &name, Node *parent);
	void update(Attribute *attribute);

private:
	NumericAttribute *_array;
	NumericAttribute *_size;
};

class BuildArray: public Node{
public:
	BuildArray(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void attributeSpecializationChanged(Attribute *attribute);
	void update(Attribute *attribute);
	void addNumericAttribute();
	
private:
	NumericAttribute *_array;
	void(BuildArray::*_selectedOperation)(const std::vector<Attribute*>&, int, Numeric*);
	void updateInt(const std::vector<Attribute*> &inAttrs, int arraySize, Numeric *array);
	void updateFloat(const std::vector<Attribute*> &inAttrs, int arraySize, Numeric *array);
	void updateVec3(const std::vector<Attribute*> &inAttrs, int arraySize, Numeric *array);
	void updateCol4(const std::vector<Attribute*> &inAttrs, int arraySize, Numeric *array);
	void updateMatrix44(const std::vector<Attribute*> &inAttrs, int arraySize, Numeric *array);
};

class RangeArray: public Node{
public:
	RangeArray(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void attributeSpecializationChanged(Attribute *attribute);
	void update(Attribute *attribute);
	
private:
	void(RangeArray::*_selectedOperation)(Numeric*, Numeric*, int, Numeric*);
	void updateInt(Numeric *start, Numeric *end, int steps, Numeric *array);
	void updateFloat(Numeric *start, Numeric *end, int steps, Numeric *array);
	NumericAttribute *_start;
	NumericAttribute *_end;
	NumericAttribute *_steps;
	NumericAttribute *_array;
};

class Matrix44Translation: public Node{
public:
	Matrix44Translation(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);
	
private:
	NumericAttribute *_matrix;
	NumericAttribute *_translation;
};

class Matrix44RotationAxis: public Node{
public:
	Matrix44RotationAxis(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);
	
private:
	NumericAttribute *_matrix;
	NumericAttribute *_axisX;
	NumericAttribute *_axisY;
	NumericAttribute *_axisZ;
};

class Matrix44EulerRotation: public Node{
public:
	Matrix44EulerRotation(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);
	
private:
	NumericAttribute *_matrix;
	NumericAttribute *_eulerAngles;
};

class Matrix44FromVectors: public Node{
public:
	Matrix44FromVectors(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);
	
private:
	NumericAttribute *_translation;
	NumericAttribute *_axisX;
	NumericAttribute *_axisY;
	NumericAttribute *_axisZ;
	NumericAttribute *_scale;
	NumericAttribute *_matrix;
};

class RangeLoop: public Node{
public:
	RangeLoop(const std::string &name, Node *parent);
	void attributeSpecializationChanged(Attribute *attribute);
	void update(Attribute *attribute);
	
private:
	NumericAttribute *_start;
	NumericAttribute *_end;
	NumericAttribute *_step;
	NumericAttribute *_valueInRange;
	void(RangeLoop::*_selectedOperation)(Numeric *, Numeric *, Numeric *, Numeric *);
	
	void updateFloat(Numeric *start, Numeric *end, Numeric *step, Numeric *out);
	void updateFloatArray(Numeric *start, Numeric *end, Numeric *step, Numeric *out);
	void updateInt(Numeric *start, Numeric *end, Numeric *step, Numeric *out);
	void updateIntArray(Numeric *start, Numeric *end, Numeric *step, Numeric *out);
};

class RandomNumber: public Node{
public:
	RandomNumber(const std::string &name, Node *parent);
	void attributeSpecializationChanged(Attribute *attribute);
	void update(Attribute *attribute);

private:
	NumericAttribute *_min;
	NumericAttribute *_max;
	NumericAttribute *_out;
	void(RandomNumber::*_selectedOperation)(Numeric *, Numeric *, Numeric *);
	
	void updateFloat(Numeric *min, Numeric *max, Numeric *out);
	void updateFloatArray(Numeric *min, Numeric *max, Numeric *out);
	void updateInt(Numeric *min, Numeric *max, Numeric *out);
	void updateIntArray(Numeric *min, Numeric *max, Numeric *out);
};

class NumericIterator: public LoopIteratorNode{
public:
	NumericIterator(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void attributeSpecializationChanged(Attribute *attribute);
	void loopStart(unsigned int loopRangeSize);
	void loopStep(unsigned int index);

private:
	NumericAttribute *_element;
	NumericAttribute *_array;
	void(NumericIterator::*_selectedOperation)(unsigned int, Numeric *, Numeric *);
	
	void stepInt(unsigned int index, Numeric *element, Numeric *array);
	void stepFloat(unsigned int index, Numeric *element, Numeric *array);
	void stepVec3(unsigned int index, Numeric *element, Numeric *array);
	void stepCol4(unsigned int index, Numeric *element, Numeric *array);
	void stepMatrix44(unsigned int index, Numeric *element, Numeric *array);
};

class ArrayIndices: public Node{
public:
	ArrayIndices(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	
private:
	NumericAttribute *_array;
	NumericAttribute *_indices;
};

class GetArrayElement: public Node{
public:
	GetArrayElement(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void attributeSpecializationChanged(Attribute *attribute);
	void update(Attribute *attribute);	

private:
	NumericAttribute *_array;
	NumericAttribute *_index;
	NumericAttribute *_element;
	void(GetArrayElement::*_selectedOperation)(Numeric *, const std::vector<int> &, Numeric *);
	
	void updateInt(Numeric *array, const std::vector<int> &index, Numeric *element);
	void updateFloat(Numeric *array, const std::vector<int> &index, Numeric *element);
	void updateVec3(Numeric *array, const std::vector<int> &index, Numeric *element);
	void updateCol4(Numeric *array, const std::vector<int> &index, Numeric *element);
	void updateMatrix44(Numeric *array, const std::vector<int> &index, Numeric *element);
};

class SetArrayElement: public Node{
public:
	SetArrayElement(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void attributeSpecializationChanged(Attribute *attribute);
	void update(Attribute *attribute);	
	
private:
	NumericAttribute *_array;
	NumericAttribute *_index;
	NumericAttribute *_element;
	NumericAttribute *_outArray;
	void(SetArrayElement::*_selectedOperation)(Numeric *, const std::vector<int> &, Numeric *, Numeric *);

	void updateInt(Numeric *array, const std::vector<int> &index, Numeric *element, Numeric *outArray);
	void updateFloat(Numeric *array, const std::vector<int> &index, Numeric *element, Numeric *outArray);
	void updateVec3(Numeric *array, const std::vector<int> &index, Numeric *element, Numeric *outArray);
	void updateCol4(Numeric *array, const std::vector<int> &index, Numeric *element, Numeric *outArray);
	void updateMatrix44(Numeric *array, const std::vector<int> &index, Numeric *element, Numeric *outArray);
};

class SetSimulationStep: public Node{
public:
	SetSimulationStep(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	
private:
	StringAttribute *_storageKey;
	NumericAttribute *_data;
	NumericAttribute *_result;
};

class GetSimulationStep: public Node{
public:
	GetSimulationStep(const std::string &name, Node *parent);
	void update(Attribute *attribute);
	
private:
	StringAttribute *_storageKey;
	NumericAttribute *_source;
	NumericAttribute *_step;
	NumericAttribute *_data;
};

class QuatToAxisAngle: public Node
{
public:
	QuatToAxisAngle(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);

private:
	NumericAttribute *_quat;
	NumericAttribute *_axis;
	NumericAttribute *_angle;
};

class QuatToEulerRotation: public Node
{
public:
	QuatToEulerRotation(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);

private:
	NumericAttribute *_quat;
	NumericAttribute *_euler;
};

class QuatToMatrix44: public Node
{
public:
	QuatToMatrix44(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);

private:
	NumericAttribute *_quat;
	NumericAttribute *_matrix;
};

class Matrix44ToQuat: public Node
{
public:
	Matrix44ToQuat(const std::string &name, Node *parent);
	void updateSpecializationLink(Attribute *attributeA, Attribute *attributeB, std::vector<std::string> &specializationA, std::vector<std::string> &specializationB);
	void update(Attribute *attribute);

private:
	NumericAttribute *_quat;
	NumericAttribute *_matrix;
};

}
#endif


