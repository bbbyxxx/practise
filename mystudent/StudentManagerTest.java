package com.mystudent;

import java.util.ArrayList;
import java.util.Scanner;

/*
 * 这是我的学生管理系统的主类
 * 步骤如下：
 * a：定义学生类
 * b：学生管理系统主界面的代码编写
 * c：学生管理系统的查看所有学生的代码编写
 * d：学生管理系统的添加学生的代码编写
 * e：学生管理系统的删除学生的代码编写
 * f：学生管理系统的修改学生的代码编写
 */
public class StudentManagerTest {
	public static void main(String[] args) {
		//创建集合对象用于存储学生数据
		ArrayList<Student> array = new ArrayList<>();
		//这是学生管理系统的主界面
		while(true){
			System.out.println("------欢迎来到学生管理系统------");
			System.out.println("------1查看所有学生------");
			System.out.println("------2添加学生------");
			System.out.println("------3删除学生------");
			System.out.println("------4修改学生------");
			System.out.println("------5退出------");
			System.out.print("请输入你的选择：");
			//创建键盘录入对象
			Scanner sc = new Scanner(System.in);
			String choiceString = sc.nextLine();
			//用switch语句实现选择
			switch(choiceString){
			case"1":
				//查看所有学生
				findAllStudent(array);
				break;
			case"2":
				//添加学生
				addStudent(array);
				break;
			case"3":
				//删除学生
				deleteStudent(array);
				break;
			case"4":
				//修改学生
				updateStudent(array);
				break;
			default:
				System.out.println("谢谢你的使用");
				System.exit(0);//JVM退出
				break;
			}
		}
	}
	
	//查看所有学生
	public static void findAllStudent(ArrayList<Student> array){
		//首先来判断集合中是否有数据，如果没有，就给出提示，并让该方法不继续执行
		if(array.size()==0){
			System.out.println("不好意思！集合中无数据！请重新选择！");
			return;
		}
		System.out.println("学号\t\t姓名\t年龄\t居住地");
		for(int x=0;x<array.size();x++){
			Student s = array.get(x);
			System.out.println(s.getId()+"\t\t"+s.getName()+"\t"+s.getAge()+"\t"+s.getAddress());
		}
	}
	
	//添加学生
	public static void addStudent(ArrayList<Student> array){
		//键盘录入对象
		String id;
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入学生学号：\r\n");
		while(true){
			id = sc.nextLine();
			//判断学号有没有被人占用
			//遍历集合，得到每一个学生的学号
			boolean flag = false;
			for(int x = 0;x<array.size();x++){
				Student s = array.get(x);
				if(s.getId().equals(id)){
					flag = true;//说明学号被占用
					break;
				}
			}
			if(flag==true){
				System.out.println("你输入的学号已经被占用！请重新输入:");
			}else{
				break;//结束循环
			}
		}
		System.out.print("请输入学生姓名：\r\n");
		String name = sc.nextLine();
		System.out.print("请输入学生年龄：\r\n");
		String age = sc.nextLine();
		System.out.print("请输入学生居住地：\r\n");
		String address = sc.nextLine();

		//创建学生对象
		Student s = new Student();
		s.setId(id);
		s.setName(name);
		s.setAge(age);
		s.setAddress(address);

		//把学生对象作为元素添加到集合
		array.add(s);
		//给出提示
		System.out.println("添加学生成功!");
	}
	
	//删除学生
	public static void deleteStudent(ArrayList<Student> array){
		//键盘录入一个学号，到集合中去查找，看是否有学生学号使用的是该学号，是就删除
		//创建键盘录入对象
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入你要删除的学生的学号：");
		String id = sc.nextLine();
		
		//遍历集合
		/*for(int x=0;x<array.size();x++){
			//获取到每一个学生对象
			Student s = array.get(x);
			//比较
			if(s.getId().equals(id)){
				array.remove(x);//根据索引删除
				break;
			}
		}
		//给出提示
		System.out.println("删除成功！");*/
		
		//学号不存在的提示
		//定义一个索引
		int index = -1;
		//遍历集合
		for(int x=0;x<array.size();x++){
			//获取到每一个学生对象
			Student s = array.get(x);
			//比较
			if(s.getId().equals(id)){
				index = x;
				break;
			}
		}
		if(index == -1){
			System.out.println("对不起！你要删除的学号对应的学生信息不存在！请重新返回选择：");
		}else{
			array.remove(index);//根据索引删除
			System.out.println("删除成功！");
		}
	}
	
	//修改学生
	public static void updateStudent(ArrayList<Student> array){
		//修改学生：键盘录入一个学号到集合中查找，是否有此学生就修改
		//创建键盘录入对象
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入你要修改学生的学号：");
		String id = sc.nextLine();
		
		//定义一个索引
		int index = -1;
		//遍历集合
		for(int x=0;x<array.size();x++){
			//获取每一个学生对象
			Student s = array.get(x);
			//判断
			if(s.getId().equals(id)){
				index = x;
				break;
			}
		}
		if(index ==-1){
			System.out.println("对不起！你要修改的学号对应的学生信息不存在！请重新返回选择：");
		}else{
			System.out.println("请输入学生新姓名：");
			String name = sc.nextLine();
			System.out.println("请输入学生新年龄：");
			String age = sc.nextLine();
			System.out.println("请输入学生新居住地：");
			String address = sc.nextLine();
			
			//创建学生对象
			Student s = new Student();
			s.setId(id);
			s.setName(name);
			s.setAge(age);
			s.setAddress(address);
			
			//修改集合中的学生对象
			array.set(index,s);
		}
	}
}
