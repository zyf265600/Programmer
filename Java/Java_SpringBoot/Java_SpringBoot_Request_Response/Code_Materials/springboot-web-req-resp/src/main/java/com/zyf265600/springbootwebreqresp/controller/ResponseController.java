package com.zyf265600.springbootwebreqresp.controller;

//@RestController
//public class ResponseController {
//    //响应字符串
//    @RequestMapping("/hello")
//    public String hello(){
//        System.out.println("Hello World ~");
//        return "Hello World ~";
//    }
//    //响应实体对象
//    @RequestMapping("/getAddr")
//    public Address getAddr(){
//        Address addr = new Address();//创建实体类对象
//        addr.setProvince("广东");
//        addr.setCity("深圳");
//        return addr;
//    }
//    //响应集合数据
//    @RequestMapping("/listAddr")
//    public List<Address> listAddr(){
//        List<Address> list = new ArrayList<>();//集合对象
//
//        Address addr = new Address();
//        addr.setProvince("广东");
//        addr.setCity("深圳");
//
//        Address addr2 = new Address();
//        addr2.setProvince("陕西");
//        addr2.setCity("西安");
//
//        list.add(addr);
//        list.add(addr2);
//        return list;
//    }
//}

import com.zyf265600.springbootwebreqresp.pojo.Address;
import com.zyf265600.springbootwebreqresp.pojo.Result;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.ArrayList;
import java.util.List;

@RestController
public class ResponseController {
    //响应统一格式的结果
    @RequestMapping("/hello")
    public Result hello(){
        System.out.println("Hello World ~");
        //return new Result(1,"success","Hello World ~");
        return Result.success("Hello World ~");
    }

    //响应统一格式的结果
    @RequestMapping("/getAddr")
    public Result getAddr(){
        Address addr = new Address();
        addr.setProvince("广东");
        addr.setCity("深圳");
        return Result.success(addr);
    }

    //响应统一格式的结果
    @RequestMapping("/listAddr")
    public Result listAddr(){
        List<Address> list = new ArrayList<>();

        Address addr = new Address();
        addr.setProvince("广东");
        addr.setCity("深圳");

        Address addr2 = new Address();
        addr2.setProvince("陕西");
        addr2.setCity("西安");

        list.add(addr);
        list.add(addr2);
        return Result.success(list);
    }
}
