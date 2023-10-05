import { Component, ElementRef, ViewChild, AfterViewInit, QueryList, ViewChildren } from "@angular/core"

interface Task {
  person?: {
    name: string
  }
}
interface List {
  id: number
  name: string
  age: number
}


@Component({
  // 指定组件的使用方式, 当前为标记形式
  // app-home   =>  <app-home></app-home>
  // [app-home] =>  <div app-home></div>
  // .app-home  =>  <div class="app-home"></div>
  selector: 'app-root',
  // 关联组件模板文件
  // templateUrl:'组件模板文件路径'
  // template:`组件模板字符串`
  templateUrl: './app.component.html',
  // 关联组件样式文件
  // styleUrls : ['组件样式文件路径']
  // styles : [`组件样式`]
  styleUrls: ["./app.component.css"]
})
export class AppComponent implements AfterViewInit {
  title: string = 'angular-test';

  message: string = 'Bonding Data';

  getInfo() {
    return this.message + ' with Function';
  }

  a = 1;
  b = 2;

  htmlSnippet: string = '<h1>HTML Snippet</h1>';

  img: string = '../assets/images/4.png';

  isActive: boolean = true;
  isActive1: boolean = true;
  isActive2: boolean = true;

  isActive3: boolean = false;
  color: string = 'blue';

  onSave(event: Event) {
    // this 指向组件类的实例对象
    this.title = "test";
    console.log(event);
    console.log(this);
  }

  onKeyUp() {
    console.log('Enter was pressed');
  }

  onClick(button: HTMLButtonElement, para: HTMLParagraphElement) {
    console.log(button);
    console.log(para);
  }

  @ViewChild('paragraph') par: ElementRef<HTMLParagraphElement> | undefined;
  @ViewChildren('items') items: QueryList<ElementRef<HTMLLIElement>> | undefined;

  ngAfterViewInit() {
    // 打印 paragraph 元素
    console.log(this.par?.nativeElement);

    // 打印 items 查询列表
    console.log(this.items?.toArray().map(item => item.nativeElement));
  }

  task: Task = {
    person: {
      name: 'zhangsan'
    }
  }

  list: List[] = [
    { id: 1, name: "York", age: 20 },
    { id: 2, name: "Yoma", age: 30 }
  ]

  item_s = ['Item 1', 'Item 2', 'Item 3'];

  identify(index: number, item: any): number {
    // console.log(index);
    // console.log(item);
    return item.id;
  }

  date = new Date();
  money = 12345;
  test = {
    person: {
      
    }
  }

}
