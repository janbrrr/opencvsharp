#ifndef _CPP_CORE_FILENODE_H_
#define _CPP_CORE_FILENODE_H_

#include "include_opencv.h"

CVAPI(cv::FileNode*) core_FileNode_new1()
{
    return new cv::FileNode();
}
CVAPI(cv::FileNode*) core_FileNode_new3(cv::FileNode *node)
{
    return new cv::FileNode(*node);
}

CVAPI(void) core_FileNode_delete(cv::FileNode *node)
{
    delete node;
}

CVAPI(cv::FileNode*) core_FileNode_operatorThis_byString(cv::FileNode *obj, const char *nodeName)
{
    cv::FileNode ret = (*obj)[nodeName];
    return new cv::FileNode(ret);
}
CVAPI(cv::FileNode*) core_FileNode_operatorThis_byInt(cv::FileNode *obj, int i)
{
    cv::FileNode ret = (*obj)[i];
    return new cv::FileNode(ret);
}
CVAPI(int) core_FileNode_type(cv::FileNode *obj)
{
    return obj->type();
}

CVAPI(int) core_FileNode_empty(cv::FileNode *obj)
{
    return obj->empty() ? 1 : 0;
}
CVAPI(int) core_FileNode_isNone(cv::FileNode *obj)
{
    return obj->isNone() ? 1 : 0;
}
CVAPI(int) core_FileNode_isSeq(cv::FileNode *obj)
{
    return obj->isSeq() ? 1 : 0;
}
CVAPI(int) core_FileNode_isMap(cv::FileNode *obj)
{
    return obj->isMap() ? 1 : 0;
}
CVAPI(int) core_FileNode_isInt(cv::FileNode *obj)
{
    return obj->isInt() ? 1 : 0;
}
CVAPI(int) core_FileNode_isReal(cv::FileNode *obj)
{
    return obj->isReal() ? 1 : 0;
}
CVAPI(int) core_FileNode_isString(cv::FileNode *obj)
{
    return obj->isString() ? 1 : 0;
}
CVAPI(int) core_FileNode_isNamed(cv::FileNode *obj)
{
    return obj->isNamed() ? 1 : 0;
}

CVAPI(void) core_FileNode_name(cv::FileNode *obj, char *buf, int bufLength)
{
    std::string str = obj->name();
    copyString(str, buf, bufLength);
}
CVAPI(size_t) core_FileNode_size(cv::FileNode *obj)
{
    return  obj->size();
}

CVAPI(int) core_FileNode_toInt(cv::FileNode *obj)
{
    return (int)(*obj);
}
CVAPI(float) core_FileNode_toFloat(cv::FileNode *obj)
{
    return (float)(*obj);
}
CVAPI(double) core_FileNode_toDouble(cv::FileNode *obj)
{
    return (double)(*obj);
}
CVAPI(void) core_FileNode_toString(cv::FileNode *obj, char *buf, int bufLength)
{
    std::string str = (std::string)(*obj);
    copyString(str, buf, bufLength);
}
CVAPI(void) core_FileNode_toMat(cv::FileNode *obj, cv::Mat *m)
{
    (*obj) >> (*m);
}

CVAPI(cv::FileNodeIterator*) core_FileNode_begin(cv::FileNode *obj)
{
    return new cv::FileNodeIterator(obj->begin());
}
CVAPI(cv::FileNodeIterator*) core_FileNode_end(cv::FileNode *obj)
{
    return new cv::FileNodeIterator(obj->end());
}

CVAPI(ExceptionStatus) core_FileNode_readRaw(cv::FileNode *obj, const char *fmt, uchar* vec, size_t len)
{
    BEGIN_WRAP
    obj->readRaw(fmt, vec, len);
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_int(cv::FileNode *node, int *value, int default_value)
{
    BEGIN_WRAP
    int temp;
    cv::read(*node, temp, default_value);
    *value = temp;
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_float(cv::FileNode *node, float *value, float default_value)
{
    BEGIN_WRAP
    float temp;
    cv::read(*node, temp, default_value);
    *value = temp;
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_double(cv::FileNode *node, double *value, double default_value)
{
    BEGIN_WRAP
    double temp;
    cv::read(*node, temp, default_value);
    *value = temp;
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_String(cv::FileNode *node, std::string *value, const char *default_value)
{
    BEGIN_WRAP
    cv::String str;
    cv::read(*node, str, (default_value == NULL) ? cv::String() : cv::String(default_value));
    value->assign(str);
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Mat(cv::FileNode *node, cv::Mat *mat, cv::Mat *default_mat)
{
    BEGIN_WRAP
    cv::read(*node, *mat, entity(default_mat));
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_SparseMat(cv::FileNode *node, cv::SparseMat *mat, cv::SparseMat *default_mat)
{
    BEGIN_WRAP
    cv::read(*node, *mat, entity(default_mat));
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_vectorOfKeyPoint(cv::FileNode *node, std::vector<cv::KeyPoint> *keypoints)
{
    BEGIN_WRAP
    cv::read(*node, *keypoints);
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_vectorOfDMatch(cv::FileNode *node, std::vector<cv::DMatch> *matches)
{
    BEGIN_WRAP
    cv::read(*node, *matches);
    END_WRAP
}


CVAPI(ExceptionStatus) core_FileNode_read_Range(cv::FileNode *node, MyCvSlice *returnValue)
{
    BEGIN_WRAP
    cv::Range ret;
    (*node) >> ret;
    *returnValue = c(ret);
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_KeyPoint(cv::FileNode *node, MyKeyPoint *returnValue)
{   
    BEGIN_WRAP 
    cv::KeyPoint ret;
    (*node) >> ret;
    *returnValue = c(ret);
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_DMatch(cv::FileNode *node, MyDMatch *returnValue)
{
    BEGIN_WRAP
    cv::DMatch ret;
    (*node) >> ret;
    *returnValue = c(ret);
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_Point2i(cv::FileNode *node, MyCvPoint *returnValue)
{
    BEGIN_WRAP
    cv::Point2i ret;
    (*node) >> ret;
    *returnValue = MyCvPoint{ ret.x, ret.y };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Point2f(cv::FileNode *node, MyCvPoint2D32f *returnValue)
{
    BEGIN_WRAP
    cv::Point2f ret;
    (*node) >> ret;
    *returnValue = MyCvPoint2D32f{ ret.x, ret.y };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Point2d(cv::FileNode *node, MyCvPoint2D64f *returnValue)
{
    BEGIN_WRAP
    cv::Point2d ret;
    (*node) >> ret;
    *returnValue = MyCvPoint2D64f{ ret.x, ret.y };
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_Point3i(cv::FileNode *node, MyCvPoint3D32i *returnValue)
{
    BEGIN_WRAP
    cv::Point3i ret;
    (*node) >> ret;
    *returnValue = MyCvPoint3D32i{ ret.x, ret.y, ret.z };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Point3f(cv::FileNode *node, MyCvPoint3D32f *returnValue)
{
    BEGIN_WRAP
    cv::Point3f ret;
    (*node) >> ret;
    *returnValue = MyCvPoint3D32f{ ret.x, ret.y, ret.z };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Point3d(cv::FileNode *node, MyCvPoint3D64f *returnValue)
{
    BEGIN_WRAP
    cv::Point3d ret;
    (*node) >> ret;
    *returnValue = MyCvPoint3D64f{ ret.x, ret.y, ret.z };
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_Size2i(cv::FileNode *node, MyCvSize *returnValue)
{
    BEGIN_WRAP
    cv::Size2i ret;
    (*node) >> ret;
    *returnValue = MyCvSize{ ret.width, ret.height };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Size2f(cv::FileNode *node, MyCvSize2D32f *returnValue)
{
    BEGIN_WRAP
    cv::Size2f ret;
    (*node) >> ret;
    *returnValue = MyCvSize2D32f{ ret.width, ret.height };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Size2d(cv::FileNode *node, MyCvSize2D64f *returnValue)
{
    BEGIN_WRAP
    cv::Size2d ret;
    (*node) >> ret;
    *returnValue = MyCvSize2D64f{ ret.width, ret.height };
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_Rect2i(cv::FileNode *node, MyCvRect *returnValue)
{
    BEGIN_WRAP
    cv::Rect2i ret;
    (*node) >> ret;
    *returnValue = MyCvRect{ ret.x, ret.y, ret.width, ret.height };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Rect2f(cv::FileNode *node, MyCvRect2D32f *returnValue)
{
    BEGIN_WRAP
    cv::Rect2f ret;
    (*node) >> ret;
    *returnValue = MyCvRect2D32f{ ret.x, ret.y, ret.width, ret.height };
    END_WRAP
}
CVAPI(ExceptionStatus) core_FileNode_read_Rect2d(cv::FileNode *node, MyCvRect2D64f *returnValue)
{
    BEGIN_WRAP
    cv::Rect2d ret;
    (*node) >> ret;
    *returnValue = MyCvRect2D64f{ ret.x, ret.y, ret.width, ret.height };
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_Scalar(cv::FileNode *node, MyCvScalar *returnValue)
{
    BEGIN_WRAP
    cv::Scalar s;
    (*node) >> s;
    *returnValue = MyCvScalar{};
    returnValue->val[0] = s.val[0];
    returnValue->val[1] = s.val[1];
    returnValue->val[2] = s.val[2];
    returnValue->val[3] = s.val[3];
    END_WRAP
}

CVAPI(ExceptionStatus) core_FileNode_read_Vec2i(cv::FileNode *node, CvVec2i *returnValue) { BEGIN_WRAP cv::Vec2i v; (*node) >> v; CvVec2i ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec3i(cv::FileNode *node, CvVec3i *returnValue) { BEGIN_WRAP cv::Vec3i v; (*node) >> v; CvVec3i ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec4i(cv::FileNode *node, CvVec4i *returnValue) { BEGIN_WRAP cv::Vec4i v; (*node) >> v; CvVec4i ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec6i(cv::FileNode *node, CvVec6i *returnValue) { BEGIN_WRAP cv::Vec6i v; (*node) >> v; CvVec6i ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec2d(cv::FileNode *node, CvVec2d *returnValue) { BEGIN_WRAP cv::Vec2d v; (*node) >> v; CvVec2d ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec3d(cv::FileNode *node, CvVec3d *returnValue) { BEGIN_WRAP cv::Vec3d v; (*node) >> v; CvVec3d ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec4d(cv::FileNode *node, CvVec4d *returnValue) { BEGIN_WRAP cv::Vec4d v; (*node) >> v; CvVec4d ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec6d(cv::FileNode *node, CvVec6d *returnValue) { BEGIN_WRAP cv::Vec6d v; (*node) >> v; CvVec6d ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec2f(cv::FileNode *node, CvVec2f *returnValue) { BEGIN_WRAP cv::Vec2f v; (*node) >> v; CvVec2f ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec3f(cv::FileNode *node, CvVec3f *returnValue) { BEGIN_WRAP cv::Vec3f v; (*node) >> v; CvVec3f ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec4f(cv::FileNode *node, CvVec4f *returnValue) { BEGIN_WRAP cv::Vec4f v; (*node) >> v; CvVec4f ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec6f(cv::FileNode *node, CvVec6f *returnValue) { BEGIN_WRAP cv::Vec6f v; (*node) >> v; CvVec6f ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec2b(cv::FileNode *node, CvVec2b *returnValue) { BEGIN_WRAP cv::Vec2b v; (*node) >> v; CvVec2b ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec3b(cv::FileNode *node, CvVec3b *returnValue) { BEGIN_WRAP cv::Vec3b v; (*node) >> v; CvVec3b ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec4b(cv::FileNode *node, CvVec4b *returnValue) { BEGIN_WRAP cv::Vec4b v; (*node) >> v; CvVec4b ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec6b(cv::FileNode *node, CvVec6b *returnValue) { BEGIN_WRAP cv::Vec6b v; (*node) >> v; CvVec6b ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec2s(cv::FileNode *node, CvVec2s *returnValue) { BEGIN_WRAP cv::Vec2s v; (*node) >> v; CvVec2s ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec3s(cv::FileNode *node, CvVec3s *returnValue) { BEGIN_WRAP cv::Vec3s v; (*node) >> v; CvVec3s ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec4s(cv::FileNode *node, CvVec4s *returnValue) { BEGIN_WRAP cv::Vec4s v; (*node) >> v; CvVec4s ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec6s(cv::FileNode *node, CvVec6s *returnValue) { BEGIN_WRAP cv::Vec6s v; (*node) >> v; CvVec6s ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec2w(cv::FileNode *node, CvVec2w *returnValue) { BEGIN_WRAP cv::Vec2w v; (*node) >> v; CvVec2w ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec3w(cv::FileNode *node, CvVec3w *returnValue) { BEGIN_WRAP cv::Vec3w v; (*node) >> v; CvVec3w ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec4w(cv::FileNode *node, CvVec4w *returnValue) { BEGIN_WRAP cv::Vec4w v; (*node) >> v; CvVec4w ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }
CVAPI(ExceptionStatus) core_FileNode_read_Vec6w(cv::FileNode *node, CvVec6w *returnValue) { BEGIN_WRAP cv::Vec6w v; (*node) >> v; CvVec6w ret; std::copy(std::begin(v.val), std::end(v.val), std::begin(ret.val)); *returnValue = ret; END_WRAP }

#endif