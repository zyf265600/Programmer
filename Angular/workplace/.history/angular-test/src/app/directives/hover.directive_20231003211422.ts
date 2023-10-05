import { AfterViewInit, Directive, ElementRef, Input } from '@angular/core';

interface Options{
  bgColor?: string
}

@Directive({
  selector: '[appHover]'
})
export class HoverDirective implements AfterViewInit{
  @Input("appHover") a: Options = {}
  element: HTMLElement;

  constructor(private elementRef: ElementRef) {
    this.element = elementRef.nativeElement;
  }

  ngAfterViewInit(): void {
    this.element.style.backgroundColor = this.a.bgColor || "skyblue";
  }

}
