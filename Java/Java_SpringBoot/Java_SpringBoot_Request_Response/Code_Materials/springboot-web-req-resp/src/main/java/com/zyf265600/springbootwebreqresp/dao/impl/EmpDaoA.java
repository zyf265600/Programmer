package com.zyf265600.springbootwebreqresp.dao.impl;

import com.zyf265600.springbootwebreqresp.dao.EmpDao;
import com.zyf265600.springbootwebreqresp.pojo.Emp;
import com.zyf265600.springbootwebreqresp.utils.XmlParserUtils;

import java.util.List;

//数据访问实现类
public class EmpDaoA implements EmpDao {
    @Override
    public List<Emp> listEmp() {
        //1. 加载并解析emp.xml
        String file = this.getClass().getClassLoader().getResource("emp.xml").getFile();
        System.out.println(file);
        List<Emp> empList = XmlParserUtils.parse(file, Emp.class);
        return empList;
    }
}
