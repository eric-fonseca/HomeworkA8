/*
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2015/03
*/
#ifndef __BOUNDINGBOXCLASS_H_
#define __BOUNDINGBOXCLASS_H_

#include "MyEngine.h"

//System Class
class BoundingBoxClass
{
	bool m_bInitialized; //Has the elements of this object been initialized before?
	bool m_bIsVisible;
	vector3 m_v3Size;//Radius of the collision Box
	vector3 m_v3Min;
	vector3 m_v3Max;
	vector3 color;
	vector3 m_v3Centroid;//Center point of the model, the origin in GSpace in which the Box is going to be located
	String m_sName;//Name of the BoundingBox (to relate to the instance)

public:
	/* Constructor */
	BoundingBoxClass(void);
	/* Copy Constructor */
	BoundingBoxClass(BoundingBoxClass const& other);
	/* Copy Assignment Operator*/
	BoundingBoxClass& operator=(BoundingBoxClass const& other);
	/* Destructor */
	~BoundingBoxClass(void);

	/* Swaps the contents of the object with another object's content */
	void Swap(BoundingBoxClass& other);

	/*
	IsInitialized
		Returns information about whether or not the object has been initialized
	*/
	bool IsInitialized(void);

	vector3 GetMaxSize(void);
	vector3 GetMinSize(void);
	bool GetVisibility(void);
	vector3 GetColor(void);

	void SetColor(vector3 color);
	void SetVisibility(bool visible);

	/*
	GetCentroid
		Returns the origin of the Cartesian Coordinate System in which the cube is drawn in GSpace
	*/
	vector3 GetCentroid(void);

	/*
	GetName
		Returns the name of the Box to associate it with an instance
	*/
	String GetName(void);

	/*
	ConstructBox
		Creates the Box in local space of the model specified in the instance name
	*/
	void GenerateBoundingBox(String a_sInstanceName);

	/*
	AddBoxToRenderList
		Adds the cube to the render list specifying also if rendering the centroid is necessary
	*/
	void AddCubeToRenderList(matrix4 a_mModelToWorld, vector3 a_vColor, bool a_bRenderCentroid = false);

	
private:
	/* Releases the object from memory */
	void Release(void);

	/* Initialize the object's fields */
	void Init(void);
};


#endif //__BOUNDINGBOXCLASS_H__