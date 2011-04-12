
#ifndef __view_view_prop_h__
#define __view_view_prop_h__

#pragma once

#include "base/basic_types.h"
#include "base/ref_counted.h"

namespace view
{

    // ViewPropά����ͼ�ļ�/ֵ��, �����滻Win32��SetProp, ���ǲ����ô����ڴ����.
    // ViewProp��SetProp������һ��, ��ͼ/�����������һ�δ�����ViewProp.
    class ViewProp
    {
    public:
        // ������ͼ/����ֵ. ����Ѿ�����, ���滻.
        //
        // ViewProp���´��char*, ָ����������.
        ViewProp(HWND view, const char* key, void* data);
        ~ViewProp();

        // ������ͼ/����Ӧ������, �����ڷ���NULL.
        static void* GetValue(HWND view, const char* key);

        // ���ؼ�.
        const char* Key() const;

    private:
        class Data;

        // �洢ʵ�ʵ�����.
        scoped_refptr<Data> data_;

        DISALLOW_COPY_AND_ASSIGN(ViewProp);
    };

} //namespace view

#endif //__view_view_prop_h__