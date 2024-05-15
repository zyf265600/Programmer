import { Component } from '@angular/core';

@Component({
  selector: 'app-component-module',
  templateUrl: './component-module.component.html',
  styleUrls: ['./component-module.component.css']
})
export class ComponentModuleComponent {
  title: string = 'angular-test';
  message: string = 'Bonding Data';

  getInfo() {
    return this.message + ' with Function';
  }

  a = 1;
  b = 2;

  htmlSnippet: string = '<h1>HTML Snippet</h1>';

  img: string = '../assets/images/4.png';


}
