package com.zyf265600.springbootwebquickstart.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

//请求处理类
@RestController
public class HelloController {
    @RequestMapping("")
    public String mainPage(){
        System.out.println("Main Page~");
        return "Main Page~";
    }
    @RequestMapping("/hello")
    public String hello(){
        System.out.println("Hello World~");
        return "Hello World~";
    }
}
