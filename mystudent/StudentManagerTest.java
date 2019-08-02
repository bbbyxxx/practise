package com.mystudent;

import java.util.ArrayList;
import java.util.Scanner;

/*
 * �����ҵ�ѧ������ϵͳ������
 * �������£�
 * a������ѧ����
 * b��ѧ������ϵͳ������Ĵ����д
 * c��ѧ������ϵͳ�Ĳ鿴����ѧ���Ĵ����д
 * d��ѧ������ϵͳ�����ѧ���Ĵ����д
 * e��ѧ������ϵͳ��ɾ��ѧ���Ĵ����д
 * f��ѧ������ϵͳ���޸�ѧ���Ĵ����д
 */
public class StudentManagerTest {
	public static void main(String[] args) {
		//�������϶������ڴ洢ѧ������
		ArrayList<Student> array = new ArrayList<>();
		//����ѧ������ϵͳ��������
		while(true){
			System.out.println("------��ӭ����ѧ������ϵͳ------");
			System.out.println("------1�鿴����ѧ��------");
			System.out.println("------2���ѧ��------");
			System.out.println("------3ɾ��ѧ��------");
			System.out.println("------4�޸�ѧ��------");
			System.out.println("------5�˳�------");
			System.out.print("���������ѡ��");
			//��������¼�����
			Scanner sc = new Scanner(System.in);
			String choiceString = sc.nextLine();
			//��switch���ʵ��ѡ��
			switch(choiceString){
			case"1":
				//�鿴����ѧ��
				findAllStudent(array);
				break;
			case"2":
				//���ѧ��
				addStudent(array);
				break;
			case"3":
				//ɾ��ѧ��
				deleteStudent(array);
				break;
			case"4":
				//�޸�ѧ��
				updateStudent(array);
				break;
			default:
				System.out.println("лл���ʹ��");
				System.exit(0);//JVM�˳�
				break;
			}
		}
	}
	
	//�鿴����ѧ��
	public static void findAllStudent(ArrayList<Student> array){
		//�������жϼ������Ƿ������ݣ����û�У��͸�����ʾ�����ø÷���������ִ��
		if(array.size()==0){
			System.out.println("������˼�������������ݣ�������ѡ��");
			return;
		}
		System.out.println("ѧ��\t\t����\t����\t��ס��");
		for(int x=0;x<array.size();x++){
			Student s = array.get(x);
			System.out.println(s.getId()+"\t\t"+s.getName()+"\t"+s.getAge()+"\t"+s.getAddress());
		}
	}
	
	//���ѧ��
	public static void addStudent(ArrayList<Student> array){
		//����¼�����
		String id;
		Scanner sc = new Scanner(System.in);
		System.out.print("������ѧ��ѧ�ţ�\r\n");
		while(true){
			id = sc.nextLine();
			//�ж�ѧ����û�б���ռ��
			//�������ϣ��õ�ÿһ��ѧ����ѧ��
			boolean flag = false;
			for(int x = 0;x<array.size();x++){
				Student s = array.get(x);
				if(s.getId().equals(id)){
					flag = true;//˵��ѧ�ű�ռ��
					break;
				}
			}
			if(flag==true){
				System.out.println("�������ѧ���Ѿ���ռ�ã�����������:");
			}else{
				break;//����ѭ��
			}
		}
		System.out.print("������ѧ��������\r\n");
		String name = sc.nextLine();
		System.out.print("������ѧ�����䣺\r\n");
		String age = sc.nextLine();
		System.out.print("������ѧ����ס�أ�\r\n");
		String address = sc.nextLine();

		//����ѧ������
		Student s = new Student();
		s.setId(id);
		s.setName(name);
		s.setAge(age);
		s.setAddress(address);

		//��ѧ��������ΪԪ����ӵ�����
		array.add(s);
		//������ʾ
		System.out.println("���ѧ���ɹ�!");
	}
	
	//ɾ��ѧ��
	public static void deleteStudent(ArrayList<Student> array){
		//����¼��һ��ѧ�ţ���������ȥ���ң����Ƿ���ѧ��ѧ��ʹ�õ��Ǹ�ѧ�ţ��Ǿ�ɾ��
		//��������¼�����
		Scanner sc = new Scanner(System.in);
		System.out.println("��������Ҫɾ����ѧ����ѧ�ţ�");
		String id = sc.nextLine();
		
		//��������
		/*for(int x=0;x<array.size();x++){
			//��ȡ��ÿһ��ѧ������
			Student s = array.get(x);
			//�Ƚ�
			if(s.getId().equals(id)){
				array.remove(x);//��������ɾ��
				break;
			}
		}
		//������ʾ
		System.out.println("ɾ���ɹ���");*/
		
		//ѧ�Ų����ڵ���ʾ
		//����һ������
		int index = -1;
		//��������
		for(int x=0;x<array.size();x++){
			//��ȡ��ÿһ��ѧ������
			Student s = array.get(x);
			//�Ƚ�
			if(s.getId().equals(id)){
				index = x;
				break;
			}
		}
		if(index == -1){
			System.out.println("�Բ�����Ҫɾ����ѧ�Ŷ�Ӧ��ѧ����Ϣ�����ڣ������·���ѡ��");
		}else{
			array.remove(index);//��������ɾ��
			System.out.println("ɾ���ɹ���");
		}
	}
	
	//�޸�ѧ��
	public static void updateStudent(ArrayList<Student> array){
		//�޸�ѧ��������¼��һ��ѧ�ŵ������в��ң��Ƿ��д�ѧ�����޸�
		//��������¼�����
		Scanner sc = new Scanner(System.in);
		System.out.println("��������Ҫ�޸�ѧ����ѧ�ţ�");
		String id = sc.nextLine();
		
		//����һ������
		int index = -1;
		//��������
		for(int x=0;x<array.size();x++){
			//��ȡÿһ��ѧ������
			Student s = array.get(x);
			//�ж�
			if(s.getId().equals(id)){
				index = x;
				break;
			}
		}
		if(index ==-1){
			System.out.println("�Բ�����Ҫ�޸ĵ�ѧ�Ŷ�Ӧ��ѧ����Ϣ�����ڣ������·���ѡ��");
		}else{
			System.out.println("������ѧ����������");
			String name = sc.nextLine();
			System.out.println("������ѧ�������䣺");
			String age = sc.nextLine();
			System.out.println("������ѧ���¾�ס�أ�");
			String address = sc.nextLine();
			
			//����ѧ������
			Student s = new Student();
			s.setId(id);
			s.setName(name);
			s.setAge(age);
			s.setAddress(address);
			
			//�޸ļ����е�ѧ������
			array.set(index,s);
		}
	}
}
