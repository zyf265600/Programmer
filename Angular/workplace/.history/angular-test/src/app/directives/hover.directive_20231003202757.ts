import { Directive, ElementRef } from '@angular/core';

@Directive({
  selector: '[appHover]'
})
export class HoverDirective {

  constructor(private elementRef: ElementRef) {
    console.log(this.elementRef);
    this.elementRef.nativeElement.style.backgroundColor = 'red';
   }

}
